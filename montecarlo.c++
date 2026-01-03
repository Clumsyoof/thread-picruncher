#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <atomic>
#include <immintrin.h>

void monte_carlo_worker(long long iterations, std::atomic<long long>& global_count) {
    std::random_device rd;
    std::mt19937_64 rng(rd());
    std::uniform_real_distribution<double> dist(-1.0f, 1.0f);

    long long local_count = 0;

   //aligned arrays
    alignas(32) double x_array[4];
    alignas(32) double y_array[4];

    __m256d one = _mm256_set1_pd(1.0f); //register full of 1.0s

    for (long long i = 0; i < iterations; i += 4) {
        // Fill temporary arrays (In a real HPC app, you'd generate these faster)
        for(int j=0; j<4; ++j) {
            x_array[j] = dist(rng);
            y_array[j] = dist(rng);
        }

        //load data into AVX registers
        __m256d x = _mm256_load_pd(x_array);
        __m256d y = _mm256_load_pd(y_array);

        //math, done in 2 clock cycles using FMA
        //_mm256_fmadd_ps(x,x,_mm256_mul_ps(x,x)) is one clock cycle but has 2 problems
        //a) stuff rounded twice
        //b) fmadd is waiting for mul resulting in idelling in 1 cycle
        __m256d x2 = _mm256_mul_pd(x, x);
        __m256d dist_sq = _mm256_fmadd_pd(y,y, x2);

        // dist_sq <= 1.0
        // CoMPare LEss than or Equal to Ordered Quiet
        // NaN will return FALSE ie 0 in bitmask
        __m256d mask = _mm256_cmp_pd(dist_sq, one, _CMP_LE_OQ);

        int bitmask = _mm256_movemask_pd(mask);

        local_count += __builtin_popcount(bitmask);
    }


    global_count += local_count;
}

int main() {
    long long total_iterations = 1000000000; 
    unsigned int num_threads = std::thread::hardware_concurrency();
    long long iterations_per_thread = total_iterations / num_threads;

    std::atomic<long long> inside_count(0);
    std::vector<std::thread> threads;

    std::cout << "launching " << num_threads << " threads..." << std::endl;

    for (unsigned int i = 0; i < num_threads; ++i) {
        threads.emplace_back(monte_carlo_worker, iterations_per_thread, std::ref(inside_count));
    }

    for (auto& t : threads) {
        t.join();
    }

    double pi = 4.0 * (double)inside_count / total_iterations;
    std::cout << "pi: " << pi << std::endl;

    return 0;
}
