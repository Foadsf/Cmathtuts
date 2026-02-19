# Contributing to Cmathtuts

Thank you for your interest in contributing to Cmathtuts! We welcome contributions from everyone. This document provides guidelines for contributing to this project.

## How to Contribute

### Reporting Bugs

If you find a bug or an issue with the examples, please open an issue on GitHub. Include:
- A clear description of the issue
- Steps to reproduce it
- Your environment (OS, compiler version)

### Suggesting Enhancements

We welcome suggestions for new examples or improvements to existing ones. Please open an issue to discuss your ideas.

### Pull Requests

1.  **Fork the repository** and create a new branch for your feature or fix.
    ```bash
    git checkout -b feature/my-new-example
    ```
2.  **Make your changes**. Ensure your code follows the project's coding style (if any) and is well-documented.
    - If adding a new example, please follow the `ExXX` naming convention.
    - Include comments explaining the code, especially for mixed C/Fortran programming.
3.  **Test your changes**. Make sure the examples compile and run correctly.
4.  **Commit your changes** with descriptive commit messages.
    ```bash
    git commit -m "Add example of dgemm using CBLAS"
    ```
5.  **Push to your fork** and submit a **Pull Request**.
    ```bash
    git push origin feature/my-new-example
    ```

## Coding Guidelines

- **Language**: The project focuses on C and Fortran.
- **Style**: Try to keep the code clean and readable.
- **Documentation**: Add comments to explain complex logic or API usage.

## License

By contributing, you agree that your contributions will be licensed under the project's license (GPLv3).
