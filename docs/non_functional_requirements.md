# Non-Functional Requirements

## Usability
- Console-based user interface.
- Simple and intuitive text menus.
- Clear validation messages for invalid operations.

## Reliability
- The system must prevent double booking of rooms.
- The system must validate class capacity limits.
- The system must validate overdue payments before bookings.

## Performance
- The system should respond quickly to standard operations.
- Search and listing operations should execute without noticeable delay.

## Supportability
- The system should contain unit tests for core business rules.
- Source code must be modular and easy to maintain.

## Design Constraints
- Data must be persistent in files.
- Domain model must follow object-oriented principles.

## Implementation Constraints
- The system must be implemented in C++.
- The project must be developed using CLion and CMake.

## Interface Constraints
- Text-based console interface only.
- No graphical user interface required.