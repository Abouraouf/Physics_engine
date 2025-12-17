# Physics Shapes Project

## Overview
A simple 2D interactive simulation featuring two types of shapes: **Triangles** and **Squares**. Each shape is affected by gravity and can be dragged with the mouse. Clicking on a shape moves it to the center while leaving a copy in its original position.

## Features
- **Shapes:** Triangle and Square (up to 10 of each)  
- **Drag & Drop:** Click and hold a shape to drag it around the window  
- **Centering:** Click a shape to instantly move it to the center  
- **Gravity:** Shapes fall naturally when not being dragged  
- **Reset:** Right-click on a shape to reset it to its starting position  
- **Independent Shapes:** Each shape acts independently; collisions between different shapes are not handled  
- **Visuals:** Colored shapes for easy distinction (Triangle = Red, Square = Blue)  

## Controls
- **Left Mouse Button:**  
  - Drag a shape  
  - Click a shape to move it to the center (a copy remains in the original spot)  
- **Right Mouse Button:**  
  - Reset the selected shape to its initial position  

## Implementation Notes
- Maximum 10 triangles and 10 squares can exist at a time  
- Shapes are constrained within window boundaries  
- Gravity and dragging are calculated per frame  
- Collision with other shapes of the same type is handled; collisions between different shapes are not implemented
