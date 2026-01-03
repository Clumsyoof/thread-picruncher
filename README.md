<a id="readme-top"></a>







<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
     </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

Thread-picruncher finds the value of pi with extreme precision optimized for HPC.
<p align="right">(<a href="#readme-top">back to top</a>)</p>





<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

This project requires Intel Intrinsics and AVX2. Most modern x86 processors from AMD and Intel post 2013 will work.

If your processor is an old x86 chip, kindly check out the [Intel Intrinsics Guide](https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html) for appropriate instruction set tooling.

ARM is currently not supported.

<!-- USAGE EXAMPLES -->
## Usage
Compilation requires atleast AVX2 and FMA flags
````
//g++
g++ -O3 -mavx2 -mfma montecarlo.c++ -o montecarlo

//clang
clang++ -O3 -mavx2 -mfma montecarlo.c++ -o montecarlo

````

Or you can enable all compiler features for your cpu
````
//g++
g++ -march=native -O3 montecarlo.c++ -o montecarlo

//clang
clang++ -march=native -O3 montecarlo.c++ -o montecarlo

````

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [ ] LCG implementation
- [ ] Direct register loading
- [ ] Loop Unrolling implimentation
- [ ] ARM support

See the [open issues](https://github.com/Clumsyoof/thread-picruncher/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the project_license. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Advik.k -[LinkedIn](https://www.linkedin.com/in/advikkaushik06/) - advikkaushik478[at]gmail[dot]com
Project Link: [https://github.com/Clumsyoof/thread-picruncher](https://github.com/Clumsyoof/thread-picruncher)

<p align="right">(<a href="#readme-top">back to top</a>)</p>




