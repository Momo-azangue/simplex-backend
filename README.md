
## Project 2: Simplex Solver

### Overview

This project provides a Simplex solver for linear programming problems.
It allows users to input constraints and objective functions and solve for the optimal solution using the Simplex method.

### Technologies Used

- Node.js with Express for the server.
- React.js for the frontend.

### Prerequisites

- Node.js and npm installed.

### Getting Started

#### Backend Setup

1. **Clone the repository:**
    ```bash
    git clone <repository_url>
    cd <repository_name>
    ```

2. **Install dependencies:**
    ```bash
    npm install
    ```

3. **Start the backend server:**
    ```bash
    node server.js
    ```

#### Frontend Setup

1. **Navigate to the frontend directory:**
    ```bash
    cd frontend
    ```

2. **Install frontend dependencies:**
    ```bash
    npm install
    ```

3. **Start the frontend application:**
    ```bash
    npm start
    ```

### Usage

1. **Set Number of Constraints and Variables:**
    - Navigate to `http://localhost:3000/simplex` in your browser.
    - Enter the number of constraints and variables.

2. **Input Constraints:**
    - Enter the coefficients for each constraint and the RHS value.

3. **Input Objective Function:**
    - Enter the coefficients for the objective function.

4. **Solve the Problem:**
    - Click "Solve" to compute the optimal solution using the Simplex method.

### Example

#### Input Constraints:
```
1x1 + 0.5x2 + 1x3 + 0x4 + 0x5 <= 100
0.2x1 + 0.15x2 + 0x3 + 1x4 + 0x5 <= 25
0x1 + 1x2 + 0x3 + 0x4 + 1x5 <= 160
```

#### Input Objective Function:
```
1.5x1 + 0.9x2 + 0x3 + 0x4 + 0x5
```

#### Output Solution:
```
Optimal solution found: x1 = ..., x2 = ..., ...
```

### Troubleshooting

- Ensure the backend server is running (`node server.js`).
- Verify the frontend app is running (`npm start` in the frontend directory).

### Contributing

1. Fork the repository.
2. Create your feature branch (`git checkout -b feature/AmazingFeature`).
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`).
4. Push to the branch (`git push origin feature/AmazingFeature`).
5. Open a pull request.

### License

---

