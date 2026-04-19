# Functional Requirements

---

## UC1 - Create Athlete

| Field | Description |
|------|-------------|
| Description | Add one athlete to the system |
| Pre-condition | There are no preconditions associated with this use case. |
| Post-condition | The number of athletes has to increase by one. |

### Basic path

1. The User enters the athlete data.
2. The User saves the athlete data.
3. The System validates the athlete data.
4. The System stores the athlete data.
5. The System returns success.

### Alternative path

- Invalid data
    - The System returns failure.

---

## UC6 - Enroll Athlete in Modality

| Field | Description |
|------|-------------|
| Description | Associate one athlete to one modality |
| Pre-condition | The athlete and the modality must exist in the system. |
| Post-condition | One more enrollment is created. |

### Basic path

1. The User requests the list of athletes.
2. The System returns the list of athletes.
3. The User selects one athlete.
4. The User requests the list of modalities.
5. The System returns the list of modalities.
6. The User selects one modality.
7. The User registers the enrollment.
8. The System validates the enrollment data.
9. The System stores the enrollment.
10. The System returns success.

### Alternative path

- Invalid data
    - The System returns failure.

- Athlete already enrolled in the modality
    - The System returns failure.

---

## UC10 - Book ClassSession

| Field | Description |
|------|-------------|
| Description | Associate one athlete to one class session |
| Pre-condition | The athlete and the class session must exist in the system. |
| Post-condition | One booking is created. |

### Basic path

1. The User requests the list of athletes.
2. The System returns the list of athletes.
3. The User selects one athlete.
4. The User requests the list of class sessions.
5. The System returns the list of class sessions.
6. The User selects one class session.
7. The System validates payment status.
8. The System validates technical level.
9. The System validates class capacity.
10. The System stores the booking.
11. The System returns success.

### Alternative path

- Invalid payment status
    - The System returns failure.

- Insufficient technical level
    - The System returns failure.

- Class full
    - The System returns failure.