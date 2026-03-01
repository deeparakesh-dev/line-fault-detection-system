# Line Fault Detection System

This project presents a arduino-based line fault detection system inspired by
telecom and underground cable monitoring techniques. The system detects short-circuit
faults and estimates the relative distance of a fault using voltage-drop analysis across
a resistive cable model. The output is displayed in real time on a 16×2 LCD.

---

## 📌 Project Overview

In long-distance cable systems such as telecom or underground lines, faults often occur
due to short circuits or physical damage at unknown locations. Locating the fault
manually is time-consuming and inefficient.

This project demonstrates a **conceptual and educational prototype** that models how
line fault detection and distance estimation can be performed using basic electrical
principles and an Arduino microcontroller.

---

## 🔧 Hardware Components Used

- Arduino Uno
- 16×2 LCD (4-bit interface mode)
- Potentiometer (10kΩ) for LCD contrast control
- Resistors: 1kΩ, 2kΩ, 3kΩ (used to model cable length)
- Push button (fault simulation)
- Breadboard and jumper wires

---

## ⚙️ Working Principle

### 🔹 Cable Length Modeling

In real cable systems, electrical resistance increases proportionally with cable length.
This principle is used in the project by creating a resistor ladder network where each
resistor represents a section of the cable.

The total resistance of the network represents the total cable length.

---

### 🔹 Voltage Drop Measurement

The Arduino measures the voltage at an intermediate point in the resistor network using
its analog-to-digital converter (ADC). As cable length (resistance) increases, the
voltage drop across the line also increases, resulting in a lower sensed voltage.

---

### 🔹 Distance Estimation

The measured voltage is proportionally mapped to an estimated distance value in software.
This distance is **not a physically measured distance**, but a scaled representation used
for demonstration purposes.

> Distance is inferred from voltage drop, not directly measured.

---

### 🔹 Fault Detection Logic

A push button is used to simulate a short-circuit fault condition.

| Button State | System Status |
|-------------|--------------|
| Pressed | Short Circuit Fault Detected |
| Released | Line Status Normal |

The system continuously monitors the line condition and updates the LCD accordingly.

---

## 📟 Output Display

The 16×2 LCD displays:
- Line status (Normal / Fault)
- Estimated fault distance (scaled units)

Example output:
LINE STATUS OK
Dist: ~6.3 units


---

## 📏 About Distance Units

The distance shown on the LCD is an **estimated and scaled value** based on voltage
variations across the resistor network. The units do not represent exact meters or
kilometers unless calibrated against real cable resistance values.

This approach is commonly used in early-stage prototypes and educational demonstrations
of telecom-style fault detection systems.

---

## 🚀 Applications

- Conceptual demonstration of line fault detection
- Telecom and underground cable monitoring (educational model)
- Embedded systems and instrumentation learning
- Microcontroller-based measurement systems

---

## ⚠️ Limitations

- This is a conceptual prototype, not a field-deployable system
- Distance values are proportional estimates
- Real systems require calibrated cable parameters or advanced techniques such as
  time-domain reflectometry (TDR)

---

## 🔮 Future Improvements

- Open-circuit fault detection
- Automatic fault localization without manual input
- Real-world cable resistance calibration
- Data logging and visualization

---
