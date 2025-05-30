temperatures = c(
(10+273.15),
(55+273.15),
(100+273.15)
)
resistances = c(
70997.62,
6853.38,
19220.22
)

y <- 1 / temperatures  # 1/T
x1 <- rep(1, 3)        # Constant term for A
x2 <- log(resistances) # ln(R) term for B
x3 <- log(resistances)^3 # ln(R)^3 term for C

# Create design matrix
X <- cbind(x1, x2, x3)

  # Solve the linear system: X * coefficients = y
coefficients <- solve(X, y)

  # Extract coefficients
A <- coefficients[1]
B <- coefficients[2]
C <- coefficients[3]

coefficients
## A
## B
## C
