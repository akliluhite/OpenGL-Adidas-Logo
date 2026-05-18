# README – Adidas Logo Rendering with OpenGL Transformations

#  Project Title

Adidas Logo Rendering with Interactive Transformations and Hover Effect using OpenGL (GLUT)


#  Project Overview

This project demonstrates the rendering of the Adidas logo using OpenGL graphics primitives and interactive computer graphics concepts. The main objective of the project is to apply the fundamental concepts learned in Computer Graphics, including primitive drawing, RGB color handling, geometric transformations, keyboard interaction, and mouse-based hover effects.

The Adidas logo is constructed using polygon primitives and displayed in a 2D coordinate system using GLUT. The project allows the user to interact with the logo in real time using keyboard controls for movement, rotation, and scaling. Additionally, a hover effect was implemented as a bonus feature, where the logo changes color dynamically when the mouse pointer moves over it.


#  Concepts Implemented

##  Basic Primitives

The Adidas logo was created using OpenGL polygon primitives.

### Primitive Used:
- `GL_QUADS`

Three quadrilateral blocks were used to form the three diagonal Adidas stripes.

Each stripe is constructed using four vertices defined with normalized 2D coordinates.

### Example:
```cpp
glBegin(GL_QUADS);
    glVertex2f(-0.7f, -0.6f);
    glVertex2f(-0.33f, -0.6f);
    glVertex2f(-0.55f, -0.15f);
    glVertex2f(-0.75f, -0.45f);
glEnd();
```

---

##  Color Handling (RGB)

The project uses real-world Adidas branding colors with RGB values.

### Colors Used:

| Object | RGB Value |
|---|---|
| Adidas Logo | (0.0, 0.0, 0.0) |
| Hover Logo Color | (1.0, 1.0, 1.0) |
| Normal Background | (1.0, 1.0, 1.0) |
| Hover Background | (0.0, 0.0, 0.0) |

### Color Functions Used:
```cpp
glColor3f(0.0f, 0.0f, 0.0f);
glColor3f(1.0f, 1.0f, 1.0f);

glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
```

These colors accurately represent Adidas’ real-world black-and-white branding style.

---

#  Transformations Applied

This project implements three important geometric transformations.

---

##  Translation

Translation is used to move the logo in different directions on the screen.

### Function Used:
```cpp
glTranslatef(tx, ty, 0.0f);
```

### Keyboard Controls:

| Key | Action |
|---|---|
| W | Move Up |
| S | Move Down |
| A | Move Left |
| D | Move Right |

---

##  Rotation

Rotation is used to rotate the logo around the Z-axis.

### Function Used:
```cpp
glRotatef(angle, 0.0f, 0.0f, 1.0f);
```

### Keyboard Controls:

| Key | Action |
|---|---|
| Q | Rotate Left |
| E | Rotate Right |

---

##  Scaling

Scaling changes the size of the Adidas logo.

### Function Used:
```cpp
glScalef(scaleValue, scaleValue, 1.0f);
```

### Keyboard Controls:

| Key | Action |
|---|---|
| + | Zoom Out |

---

#  Interactive Keyboard Controls

The project uses `glutKeyboardFunc()` for real-time interaction.

### Keyboard Function:
```cpp
glutKeyboardFunc(keyboard);
```

### Complete Controls:

| Key | Function |
|---|---|
| W | Move Up |
| S | Move Down |
| A | Move Left |
| D | Move Right |
| Q | Rotate Left |
| E | Rotate Right |
| + | Zoom In |
| - | Zoom Out |
| R | Reset Transformations |

---

#  Bonus Feature – Hover Effect

An advanced hover effect was implemented as an additional creative feature beyond classroom examples.

The project detects mouse movement using passive mouse motion and changes the appearance of the logo dynamically when the mouse moves over the logo area.

---

## Hover Effect Features

### When Mouse Hovers Over Logo:
- Background changes from white to black
- Logo color changes from black to white

### Mouse Detection Function:
```cpp
glutPassiveMotionFunc(passiveMotion);
```

### Hover Detection Logic:
```cpp
if (x > -0.8f && x < 0.8f &&
    y > -0.7f && y < 0.9f)
{
    isHovered = true;
}
else {
    isHovered = false;
}
```

This feature improves interactivity and demonstrates event-driven graphics programming.

---

#  Implementation Method

The implementation process followed these steps:

1. OpenGL window initialization was performed using GLUT.
2. Orthographic projection (`gluOrtho2D`) was used for 2D rendering.
3. The Adidas logo was constructed using three quadrilateral polygons.
4. RGB color handling was implemented for logo and background rendering.
5. Transformations were applied in the following order:
   - Translation
   - Rotation
   - Scaling
6. Keyboard controls were added for interactive manipulation.
7. Mouse hover detection was implemented using passive motion callbacks.
8. `glutPostRedisplay()` was used to refresh the display after every interaction.

---

#  Challenges Faced

Several challenges were encountered during development:

- Correctly positioning vertices to accurately match the Adidas logo
- Managing transformation order for proper rendering
- Detecting hover areas accurately using mouse coordinates
- Maintaining smooth interaction with keyboard controls
- Ensuring scaling and movement did not move the logo outside the visible screen area

---

#  Group Work Division

| Member | Responsibility |
|---|---|
| Tsigereda Mitiku | Left Stripe Block, Transformations,  Hover Effect, Keyboard Controls  |
| Mahlet Bimr| Middle Stripe Block,Transformations , Hover Effect, Keyboard Controls |
| Aklilu Abelegn | Right Stripe Block, Transformations, Hover Effect, Keyboard Controls |

---
## How Left Stripe Program Works

1. The program creates an OpenGL window using the GLUT library.
2. Tsigereda implemented the left stripe of the Adidas logo using the `GL_QUADS` polygon primitive.
3. RGB color functions are used to display the stripe in black color with a white hover effect.
4. Translation is applied to move the stripe using keyboard keys (W, A, S, D).
5. Rotation and scaling transformations are implemented using Q, E, +, and - keys.
6. A hover effect changes the stripe color to white and the background to black when the mouse moves over the logo.
7. The display updates continuously using `glutPostRedisplay()` to show real-time transformations and hover interactions.
## How Middle stripe Program Works

1. The program creates an OpenGL window using the GLUT library.
2. Mahlet implemented the middle stripe of the Adidas logo using the GL_QUADS polygon primitive.
3. RGB color functions are used to display the stripe in black color.
4. Translation is applied to move the stripe using keyboard keys (W, A, S, D).
5. Rotation and scaling transformations are implemented using Q, E, +, and - keys.
6. A hover effect changes the stripe color to white and background to black when the mouse moves over the logo.
7. The display continuously updates using glutPostRedisplay() to reflect user interactions in real time.
## How Right stripe Program Works

1. The program creates an OpenGL window using the GLUT library.
2.Aklilu implemented the right stripe of the Adidas logo using the GL_QUADS polygon primitive.
3. RGB color functions are used to display the stripe in black color with a white hover effect.
4. Translation is applied to move the stripe using keyboard keys (W, A, S, D).
5. Rotation and scaling transformations are implemented using Q, E, +, and - keys.
6. A hover effect changes the stripe color to white and the background to black when the mouse moves over the logo.
7. The display updates continuously using glutPostRedisplay() to show real-time transformations and hover interactions.
#  Conclusion

This project successfully demonstrates the practical application of important Computer Graphics concepts using OpenGL and GLUT. The implementation includes primitive drawing, RGB color handling, translation, rotation, scaling, keyboard interaction, and mouse hover effects.

The addition of real-time transformations and hover interaction improves user engagement and provides a deeper understanding of graphical transformations and event-driven programming in OpenGL.

The project fulfills all required assignment criteria and also includes advanced creative features for bonus marks.
