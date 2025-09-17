# Vibration Table for Bubble Removal

This project is a **compact vibration table** designed in SolidWorks and built with a **9V DC motor** (operated at 5V), mounted under a spring-supported platform.  
The motor includes an **eccentric mass** on its shaft, generating vibrations to release trapped air bubbles in resins, plaster, and concrete, resulting in smoother surfaces and stronger casts.

---

## 🔧 Project Overview
- **Platform:** Rigid plate mounted on 4 springs  
- **Motor:** 9V 1A DC motor, powered at 5V  
- **Eccentric Mass:** Offset cap attached to the motor shaft  
- **Control:** Arduino Nano + L298N motor driver + potentiometer for variable speed  
- **Purpose:** Release bubbles before materials harden  

---

## 📐 Mathematical Model

### 1. Natural Frequency of the Platform
The platform acts as a spring–mass system.  

\[
f_n = \frac{1}{2\pi} \sqrt{\frac{k_{eq}}{m}}
\]

Where:  
- \( k_{eq} = 4k \) (4 springs in parallel)  
- \( m \) = platform + load mass  

---

### 2. Motor Frequency
The DC motor frequency is related to its RPM:

\[
f_m = \frac{N}{60}, \quad \omega = \frac{2\pi N}{60}
\]

At 5V, the motor runs at about **3000 RPM**:

\[
f_m \approx 50 \, \text{Hz}
\]

---

### 3. Excitation Force
The eccentric mass \( m_e \) at radius \( r \) produces:

\[
F(t) = m_e \, r \, \omega^2 \sin(\omega t)
\]

This is the driving force that vibrates the table.

---

### 4. Example Calculation
Assume:  
- \( k = 500 \, \text{N/m} \) per spring  
- \( m = 1.5 \, \text{kg} \)  

Then:

\[
k_{eq} = 2000 \, \text{N/m}
\]

\[
f_n = \frac{1}{2\pi} \sqrt{\frac{2000}{1.5}} \approx 5.8 \, \text{Hz}
\]

Since \( f_m \approx 50 \, \text{Hz} \), the motor runs **above resonance**, giving stable but smaller amplitude vibrations.  
Resonance tuning can be achieved by lighter springs or higher load mass.

---

## ⚡ Electronics Setup

### Components
- Arduino Nano  
- L298N motor driver  
- 10k potentiometer  
- 9V DC motor  
- External power supply (5–12V)  

### Wiring
**Potentiometer:**  
- Left pin → 5V (Arduino Nano)  
- Right pin → GND  
- Middle pin → A0  

**Arduino Nano → L298N:**  
- D9 → ENA (PWM speed control)  
- D7 → IN1  
- D8 → IN2  

**Motor:**  
- Motor + → OUT1  
- Motor – → OUT2  

**Power:**  
- External supply + → L298N `+12V` (VCC2)  
- External supply – → L298N GND  
- Arduino GND ↔ L298N GND  

---

## 💻 Arduino Code

```cpp
// Pin assignments
const int potPin = A0;  // Potentiometer input
const int enaPin = 9;   // PWM motor speed
const int in1Pin = 7;   // Direction pin 1
const int in2Pin = 8;   // Direction pin 2

void setup() {
  pinMode(enaPin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);

  // Motor direction: forward
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
}

void loop() {
  // Read potentiometer (0–1023)
  int potValue = analogRead(potPin);

  // Map to PWM (0–255)
  int pwmValue = map(potValue, 0, 1023, 0, 255);

  // Send PWM to motor
  analogWrite(enaPin, pwmValue);

  delay(10);
}


---

## 🛠️ Author
Created by [Mohamad Mrad](https://github.com/mhmdmrad)  
