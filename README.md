# Vibration Table for Bubble Removal

This project is a **custom-designed vibration table** built in SolidWorks and fabricated with a 9V DC motor and a spring-mounted platform. The table is designed to remove air bubbles from resins, concrete, and plaster by applying controlled vibrations.

---

## 🔧 Project Overview
- **Platform:** Rigid plate mounted on 4 springs  
- **Actuator:** 9V, 1A DC motor (operated at 5V for safety and control)  
- **Eccentric Mass:** Cap offset from center of motor shaft to generate unbalanced forces  
- **Support:** 4 springs provide vertical oscillation and vibration transmission  

When powered, the **eccentric weight** on the motor shaft creates a periodic force. This force excites the platform–spring system, producing vibrations that shake molds and release trapped air bubbles.

---

## 📐 Mathematical Model

### 1. Spring–Mass System
The platform and load behave like a **spring–mass system**.  
Natural frequency:

\[
f_n = \frac{1}{2\pi} \sqrt{\frac{k_{eq}}{m}}
\]

Where:  
- \(k_{eq}\): Equivalent stiffness of 4 springs (N/m)  
- \(m\): Mass of platform + load (kg)  

If each spring has stiffness \(k\):  
\[
k_{eq} = 4k
\]

---

### 2. Motor Frequency
The DC motor rotates at an angular velocity:

\[
\omega = \frac{2 \pi N}{60}
\]

Where \(N\) = motor speed in RPM.  
At 5V, a typical 9V DC motor runs around **3000 RPM**:  

\[
f_m = \frac{N}{60} \approx 50 \, \text{Hz}
\]

---

### 3. Excitation Force
The eccentric mass \(m_e\) at radius \(r\) produces a centrifugal force:

\[
F(t) = m_e \, r \, \omega^2 \, \sin(\omega t)
\]

This periodic force drives the vibration of the platform.

---

### 4. Resonance Consideration
For maximum bubble removal, vibration frequency should approach the natural frequency:

\[
f_m \approx f_n
\]

- If \(f_m < f_n\): weak vibration  
- If \(f_m = f_n\): resonance, maximum amplitude  
- If \(f_m > f_n\): reduced efficiency  

Thus, spring stiffness and platform mass must be chosen so that:

\[
f_n \approx 50 \, \text{Hz}
\]

---

### 5. Power Analysis
Motor electrical power:

\[
P = V \cdot I = 5V \times 1A = 5W
\]

Mechanical power transferred to vibration:

\[
P_{mech} \approx \frac{1}{2} m_e r^2 \omega^2
\]

(depends on eccentric mass and radius).

---

## 🧪 Example Calculation
Assume:  
- Each spring stiffness \(k = 500 \, \text{N/m}\)  
- Platform + load mass \(m = 1.5 \, \text{kg}\)  

Then:

\[
k_{eq} = 4 \times 500 = 2000 \, \text{N/m}
\]

\[
f_n = \frac{1}{2\pi} \sqrt{\frac{2000}{1.5}} \approx 5.8 \, \text{Hz}
\]

Since motor frequency \(f_m \approx 50 \, \text{Hz}\), the system runs **above resonance**, giving stable but smaller amplitude vibrations. To achieve resonance, lighter springs or heavier platform would be required.

---

## 🎯 Applications
- Resin casting  
- Plaster mold making  
- Concrete sample preparation  
- Jewelry and art projects  

---

## 📊 Future Improvements
- Optimize spring stiffness to match resonance with motor frequency  
- Add damping pads to reduce noise  
- Implement feedback sensor (accelerometer) to measure vibration amplitude  

---

## 🛠️ Author
Created by [Mohamad Mrad](https://github.com/mhmdmrad)  
