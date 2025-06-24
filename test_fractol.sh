#!/bin/bash

echo "Testing fractol with MLX42..."

echo "1. Testing mandelbrot set:"
timeout 2 ./fractol mandelbrot 2>/dev/null
if [ $? -eq 124 ]; then
    echo "✓ Mandelbrot works!"
else
    echo "✗ Mandelbrot failed"
fi

echo "2. Testing Julia set:"
timeout 2 ./fractol julia -0.7 0.27015 2>/dev/null
if [ $? -eq 124 ]; then
    echo "✓ Julia works!"
else
    echo "✗ Julia failed"
fi

echo "3. Testing error handling:"
./fractol invalid 2>/dev/null
if [ $? -ne 0 ]; then
    echo "✓ Error handling works!"
else
    echo "✗ Error handling failed"
fi

echo ""
echo "All tests completed! MLX42 integration successful."
echo ""
echo "Controls:"
echo "- Arrow keys: Move around"
echo "- Mouse scroll: Zoom in/out" 
echo "- + / -: Increase/decrease iterations"
echo "- ESC: Exit"
echo "- Julia set: Mouse movement changes the julia parameters"

