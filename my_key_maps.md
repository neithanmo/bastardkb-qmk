Creating a visual representation of your QMK keyboard's layers can greatly enhance your understanding and help with further customization. While I can't generate images directly, I can provide detailed textual diagrams for each layer, including key functions and combos. You can use these descriptions to create visual diagrams using tools like **Figma**, **Draw.io**, or **Keymap Visualizer**.

Below are the detailed representations of each layer, including the base layer, symbols, navigation, numbers, and function layers. Additionally, I’ll outline the combo actions and their corresponding key behaviors.

---

## **1. Base Layer (`LAYER_BASE`)**

### **Layout Overview:**

```
╭───────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────────────────╮
|    Q    |    W    |    F    |    P    |    B    |          |    J    |    L    |    U    |  Y_OR_ |  ;  |
├───────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────┤
|    A    | LALT_R  | LCTL_S  |  LS_T   |    G    |          |    M    | RSFT_N | RCTL_E | RALT_I | O_MINS |
├───────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────┤
|    Z    |    X    |    C    |    D    |    V    |          |    K    |    H    | HYPER_COMMA |    .    | /  |
╰───────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────╯
        LT(LAYER_NUM, ENTER)        LT(LAYER_SYM, TAB)                LWIN_T(BACKSPACE)     LT(LAYER_SYM, SPACE)
╰───────────────────────────────────────────────────────╯                  ╰────────────────────────────────────────╯
```

### **Key Definitions:**

- **Modifier Tap Layers:**

  - `LALT_R` (Left Alt when held, 'R' when tapped)
  - `LCTL_S` (Left Control when held, 'S' when tapped)
  - `LS_T` (Left Shift when held, 'T' when tapped)
  - `RSFT_N` (Right Shift when held, 'N' when tapped)
  - `RCTL_E` (Right Control when held, 'E' when tapped)
  - `RALT_I` (Right Alt when held, 'I' when tapped)

- **Tap-Hold Keys:**

  - `Y_OR_` (Y when tapped, `_` when held)
  - `O_MINS` (O when tapped, `-` when held)
  - `HYPER_COMMA` (Hyper modifier when held, `,` when tapped)

- **Layer Switches:**
  - `LT(LAYER_NUM, ENTER)` (Enter when tapped, switch to Number layer when held)
  - `LT(LAYER_SYM, TAB)` (Tab when tapped, switch to Symbol layer when held)
  - `LWIN_T(BACKSPACE)` (Left Windows when held, Backspace when tapped)
  - `LT(LAYER_SYM, SPACE)` (Space when tapped, switch to Symbol layer when held)

### **Combos Defined:**

- **Escape Combo:** `LCTL_S + RCTL_E` → `ESC`
- **Navigation Combo:** `C_LEFT + UP_COMMA` → Switch to `LAYER_BASE`
- **Caps Lock Combo:** `KC_F + KC_U` → `CAPS_LOCK`
- **Buffer Navigation:**
  - `LALT_R + LS_T` → Previous Buffer (`KC_F2`)
  - `RALT_I + RSFT_N` → Next Buffer (`KC_F3`)
- **Closing Buffer:** `KC_H + KC_DOT` → `:bd` + `ENTER`
- **Arrow Keys:**
  - `RCTL_E + RALT_I` → `UP`
  - `RSFT_N + RCTL_E` → `DOWN`
  - `LALT_R + LCTL_S` → `LEFT`
  - `LCTL_S + LS_T` → `RIGHT`
- **Special Characters:**
  - `KC_L + Y_OR_` → `{}` with cursor inside
  - `KC_W + KC_P` → `()`
  - `KC_Q + KC_B` → `[]`
- **Page Navigation:**
  - `LCTL_S + RSFT_N` → `PAGE_UP`
  - `LCTL_S + RALT_I` → `PAGE_DOWN`
- **Email Shortcut:** `KC_G + KC_M` → `neithanmo@gmail.com`
- **Backspace Combo:** `KC_W + Y_OR_` → `BACKSPACE`

---

## **2. Symbol Layer (`LAYER_SYM`)**

### **Layout Overview:**

```
╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
| BSPC |   @    |   #    |   $    |   %    |          |   [    |   (    |   )    |   ]    | BSPC |
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
| TAB  |  PEQL  |  "     |  '     |  \     |          |  &     |  {    |  }    |  *    | ENTER |
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
|  ~   |  `     | LEFT   | RIGHT  |  |     |          |  ^     | DOWN  | UP    |  !    | MO(FUN) |
╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
| BSPC | XXXXXXX |          DEL        | XXXXXXX |
╰─────────────────────────────────────────────╯                  ╰──────────────────╯
```

### **Key Definitions:**

- **Basic Symbols:**

  - `@`, `#`, `$`, `%` on top row
  - `PEQL` (Probably `+=`), `"`, `'`, `\`
  - `~`, `` ` ``, `|`, `^`, `!`

- **Navigation within Symbols:**

  - `LEFT` and `RIGHT` arrows
  - `DOWN` and `UP` arrows

- **Layer Control:**

  - `MO(FUN)` (Momentarily switch to Function layer when held)

- **Special Keys:**
  - `BSPC` (Backspace) and `ENTER`

---

## **3. Navigation Layer (`LAYER_NAV`)**

### **Layout Overview:**

```
╭─────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────╮
|  ESC  | WH_L | PGUP | PGDN | WH_R |           | XXXXXXX |  UNDO | XXXXXXX | XXXXXXX | BSPC |
├─────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
|  TAB  | BTN1 | WH_U | WH_D | XXXXXXX |          | CUT   | COPY  | PASTE | REDO  | ENTER |
├─────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
| XXXXXXX | RCTL | LEFT | RGHT | DEL |          | DOWN | UP  | RALT | XXXXXXX |
╰─────────────────────────────────────────────╤ ├────────────────────────────────────────────────────────────╯
        BTN2    | TO(BASE) |          | LWIN | ENTER
╰─────────────────────────────────────────────╯                  ╰────────────────────────╯
```

### **Key Definitions:**

- **Media and Window Controls:**

  - `WH_L` / `WH_R` (Mouse Wheel Left/Right)
  - `WH_U` / `WH_D` (Mouse Wheel Up/Down)
  - `BTN1` / `BTN2` (Mouse Buttons 1 and 2)

- **Editing Shortcuts:**

  - `CUT` (`LCTL_X`), `COPY` (`LCTL_C`), `PASTE` (`LCTL_V`), `UNDO` (`LCTL_Z`), `REDO` (`LCTL_Y`)

- **Navigation:**

  - Arrow Keys: `LEFT`, `RGHT`, `UP`, `DOWN`
  - Page Navigation: `PGUP`, `PGDN`
  - `DEL` (Delete)

- **Layer Control:**
  - `TO(BASE)` (Switch back to Base layer)

---

## **4. Number Layer (`LAYER_NUM`)**

### **Layout Overview:**

```
╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
|  ESC  | MPRV | MPLY | MNXT |  _    |          |  -    |  7    |  8    |  9    | BSPC |
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
|  TAB  | MUTE | VOLU | VOLD |  .    |          | PEQL  |  4    |  5    |  6    | SPACE |
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
| PSLS | PAST | BRIU | BRID |  +    |          |  0    |  1    |  2    |  3    |  +   |
╰─────────────────────────────────────────────╤ ├─────────────────────────────────────────────╯
         XXXXXXX | ENTER |          | LALT |  .
╰─────────────────────────────────────────────╯                  ╰───────────────────────╯
```

### **Key Definitions:**

- **Media Controls:**

  - `MPRV` (Media Previous), `MPLY` (Media Play/Pause), `MNXT` (Media Next)
  - `MUTE`, `VOLU` (Volume Up), `VOLD` (Volume Down)
  - `BRIU` (Brightness Up), `BRID` (Brightness Down)

- **Numeric Keypad:**

  - Numbers `0` through `9`
  - Basic Math Operators: `/` (`PSLS`), `*` (`PAST`), `-`, `+`
  - `PEQL` (Possibly `+=`)

- **Layer Control:**

  - `ENTER`, `SPACE`

- **Special Keys:**
  - `BSPC` (Backspace)
  - `.` (Dot)

---

## **5. Function Layer (`LAYER_FUN`)**

### **Layout Overview:**

```
╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
| XXXXXXX |  F7  |  F8  |  F9  | PSCR |          | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
| XXXXXXX |  F4  |  F5  |  F6  | QK_RBT |          |  F10  |  F11  |  F12  | XXXXXXX | XXXXXXX |
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
| XXXXXXX |  F1  |  F2  |  F3  | XXXXXXX |          | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX | XXXXXXX |
╰─────────────────────────────────────────────╤ ├─────────────────────────────────────────────╯
        TO(BASE) | XXXXXXX |          | XXXXXXX |
╰─────────────────────────────────────────────╯                  ╰────────────────────────╯
```

### **Key Definitions:**

- **Function Keys:**

  - `F1` through `F12`
  - `PSCR` (Print Screen), `QK_RBT` (Quick Reboot)

- **Layer Control:**

  - `TO(BASE)` (Switch back to Base layer)

- **Unused Keys:**
  - Represented by `XXXXXXX`

---

## **6. Combo Actions Overview**

Combos are defined as specific key combinations that trigger particular actions. Here's a summary of the combos:

| **Combo Name** | **Keys Pressed**      | **Action**                            |
| -------------- | --------------------- | ------------------------------------- |
| `ESC`          | `LCTL_S` + `RCTL_E`   | Sends `ESC` key                       |
| `NAV`          | `C_LEFT` + `UP_COMMA` | Switches to `LAYER_BASE`              |
| `CAPS_LOCK`    | `KC_F` + `KC_U`       | Activates `CAPS_LOCK`                 |
| `BUFF_PREV`    | `LALT_R` + `LS_T`     | Switches to previous buffer (`KC_F2`) |
| `BUFF_NEXT`    | `RALT_I` + `RSFT_N`   | Switches to next buffer (`KC_F3`)     |
| `CLOSE_BUFF`   | `KC_H` + `KC_DOT`     | Sends `:bd` + `ENTER`                 |
| `UP`           | `RCTL_E` + `RALT_I`   | Holds `UP` arrow key                  |
| `DOWN`         | `RSFT_N` + `RCTL_E`   | Holds `DOWN` arrow key                |
| `LEFT`         | `LALT_R` + `LCTL_S`   | Holds `LEFT` arrow key                |
| `RIGHT`        | `LCTL_S` + `LS_T`     | Holds `RIGHT` arrow key               |
| `CORCHETES`    | `KC_L` + `Y_OR_`      | Sends `{}` with cursor inside         |
| `PARENTESIS`   | `KC_W` + `KC_P`       | Sends `()`                            |
| `P_CUADRADOS`  | `KC_Q` + `KC_B`       | Sends `[]`                            |
| `PAGE_UP`      | `LCTL_S` + `RSFT_N`   | Holds `PAGE_UP`                       |
| `PAGE_DOWN`    | `LCTL_S` + `RALT_I`   | Holds `PAGE_DOWN`                     |
| `EMAIL`        | `KC_G` + `KC_M`       | Types `neithanmo@gmail.com`           |
| `BACKSPACE`    | `KC_W` + `Y_OR_`      | Holds `BACKSPACE` key                 |

### **Special Combo Behaviors:**

- **Tap-Hold Functionality:**
  - `Y_OR_`:
    - **Tap:** Sends `Y`
    - **Hold:** Sends `_`
  - `O_MINS`:
    - **Tap:** Sends `O`
    - **Hold:** Sends `-`
  - Similar behavior is defined for `H_DOWN`, `UP_COMMA`, `D_RIGHT`, and `C_LEFT`.

---

## **7. Additional Features**

### **Pointer Sniping:**

When the `LAYER_NAV` is active, pointer sniping is enabled. This feature typically allows for smooth and precise mouse movements while navigating.

### **Custom Tap-Hold Processing:**

Custom functions are implemented to handle tap or long-press actions on certain keys, enabling dual functionality based on tap or hold actions.

---

## **8. Recommendations for Visual Diagrams**

To create visual diagrams based on the descriptions above, consider the following steps:

1. **Choose a Diagramming Tool:**

    - **Figma:** Great for detailed and customizable designs.
    - **Draw.io (diagrams.net):** Free and easy to use for creating structured diagrams.
    - **Keymap Visualizer Tools:** Some online tools can generate keyboard layouts based on QMK keymaps.

2. **Design Each Layer Separately:**

    - Create separate diagrams for each layer (`LAYER_BASE`, `LAYER_SYM`, `LAYER_NAV`, `LAYER_NUM`, `LAYER_FUN`).
    - Represent keys as buttons or squares, labeling them with their respective functions.

3. **Highlight Special Keys and Combos:**

    - Use different colors or annotations to indicate modifier keys, tap-hold keys, and combo triggers.
    - For combos, you might include arrows or connecting lines showing which keys combine to perform specific actions.

4. **Use Layers Effectively:**

    - Show how pressing certain keys switches between layers.
    - Indicate momentary layer switches (`MO(LAYER_X)`) and toggle actions (`TO(LAYER_X)`).

5. **Include Legends and Annotations:**

    - Provide a legend explaining symbols like `XXXXXXX` (unused keys) and special key functions.
    - Annotate combo actions with their corresponding key combinations and outcomes.

6. **Export and Organize:**
    - Once all layers are designed, organize them in a sequence or a grid to visualize the entire keymap structure.

---

## **Example Textual Diagram for Base Layer**

Here's a simplified textual representation for the base layer that you can use as a reference:

```
+-----+-----+-----+-----+-----+     +-----+-----+-----+-------+-----+
|  Q  |  W  |  F  |  P  |  B  |     |  J  |  L  |  U  | Y_OR_ | ;   |
+-----+-----+-----+-----+-----+     +-----+-----+-----+-------+-----+
|  A  |LALT_R|LCTL_S| LS_T |  G  |     |  M  |RSFT_N|RCTL_E|RALT_I |O_MINS|
+-----+-----+-----+-----+-----+     +-----+-----+-----+-------+-----+
|  Z  |  X  |  C  |  D  |  V  |     |  K  |  H  |HYPER_,|  .   | /   |
+-----+-----+-----+-----+-----+     +-----+-----+-----+-------+-----+
| LT_NUM|LT_SYM |     LWIN_T(BSPC)    | LT_SYM(SPACE) |
+-------+-------+---------------------+---------------+
```

- **Modifiers and Special Keys:**
  - `LALT_R`: Left Alt (Hold) / R (Tap)
  - `LCTL_S`: Left Control (Hold) / S (Tap)
  - `LS_T`: Left Shift (Hold) / T (Tap)
  - `RSFT_N`: Right Shift (Hold) / N (Tap)
  - `RCTL_E`: Right Control (Hold) / E (Tap)
  - `RALT_I`: Right Alt (Hold) / I (Tap)
  - `Y_OR_`: Y (Tap) / `_` (Hold)
  - `O_MINS`: O (Tap) / `-` (Hold)
  - `HYPER_COMMA`: Hyper Modifier (Hold) / `,` (Tap)
  - `LT_NUM`: Momentary switch to Number layer
  - `LT_SYM`: Momentary switch to Symbol layer
  - `LWIN_T(BSPC)`: Left Windows (Hold) / Backspace (Tap)
  - `LT_SYM(SPACE)`: Space (Tap) / Momentary switch to Symbol layer

---

## **Conclusion**

By following the detailed textual diagrams and descriptions provided above, you can create comprehensive visual representations of your keyboard layers. These diagrams will help you better understand the layout, key functions, and combo actions, facilitating easier customization and troubleshooting.

For an even more streamlined process, consider using QMK's built-in tools or community-driven visualizers that can parse your `keymap.c` file and generate visual layouts automatically. This approach can save time and ensure accuracy in your visual diagrams.

If you need further assistance or have specific questions about any layer or key functionality, feel free to ask!
