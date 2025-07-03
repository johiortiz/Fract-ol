<div align="center">
 <!-- Project Name -->
  <h1>Fract-ol Project</h1>

  <p>
    <img src="https://img.shields.io/badge/score-110%20%2F%20100-success?style=for-the-badge" />
  </p>
</div>

## 📜 About Project

> One of the first graphical projects at 42 School, fract-ol generates beautiful fractals from the complex numbers of \
> an iterative mathematical construct. A fractal is a fragmented geometrical figure that infinitely repeats itself at \
> smaller scales. This project uses the school's graphical library, MiniLibX.

For detailed information, refer to the [**subject of this project**](README_files/fractol_subject.pdf).

	🚀 TLDR: The fract-ol project is one of the three "beginner" graphical projects of the 
 		 cursus. It teaches you about using graphic library, advanced math, and more.

> [!NOTE]  
> Because of 42 School norm requirements:
> * Each function can't have more than 25 lines of code.
> * All variables are declared and aligned at the top of each function.
> * Project should be created just with allowed functions otherwise it's cheating.

## 📑 Fractals List

The program supports these fractal sets:

| Name              | Formula                                                                                            |
|:-----------------:|:--------------------------------------------------------------------------------------------------:|
| Mandelbrot        | $z_{n+1} = z_n^2 + c, z_0 = 0$                                                                     |
| Julia             | $z_{n+1} = z_n^2 + c, z_0 = c$                                                                     |                                                           |

## 🎮 Controls

The program supports the following controls:

| Key           | Description                             |
|:-------------:|:---------------------------------------:|
| ESC           | Close the program window                |
| Keys [ESPACE] | Change the color of fractal             |
| Mouse Scroll  | Zoom in and out of the fractal          |
| ⬆️ ⬇️ ⬅️ ➡️ | Change the viewpoint                    |
| Mouse Drag    | Pan the fractal view                    |

## 👨‍💻 Usage
### Requirements

The program is written in C language and thus needs the **gcc compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the program**

To compile the program, run:

```shell
$ cd path/to/fractol && make
```

**2. How to run the program**

Run the executable too see the help message:
```shell
./fractol
```

Or run with some supported fractal:
```shell
./fractol mandelbrot
```

# 🌄 Screenshots

## Mandelbrot set
![Fractal Mandelbrot](README_files/screenshots/mandelbrot_2.png)
![Fractal Mandelbrot](README_files/screenshots/mandelbrot.png)
![Fractal Mandelbrot](README_files/screenshots/mandelbrot_3.png)
![Fractal Mandelbrot](README_files/screenshots/mandelbrot_4.png)
![Fractal Mandelbrot](README_files/screenshots/mandelbrot_5.png)
![Fractal Mandelbrot](README_files/screenshots/mandelbrot_6.png)
![Fractal Mandelbrot Animation](README_files/screenshots/fractol_mandelbrot.gif)

## Julia set

![Fractal Julia](README_files/screenshots/julia_1.png)
![Fractal Julia](README_files/screenshots/julia_2.png)
![Fractal Julia](README_files/screenshots/julia_3.png)
![Fractal Julia](README_files/screenshots/julia_4.png)
![Fractal Julia Animation](README_files/screenshots/fractol_julia.gif)
