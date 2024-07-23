<h1 align='center'> Library Management System </h1>

<p align='center'>Library Management System is a terminal-based application developed to manage books, users, and loans in a library. This project is designed to enhance your understanding of design patterns and data structures while providing a practical tool for managing library operations. </p>

## Features

- **Add New Books**: Easily add new books to the library collection.
- **Remove Books**: Remove books from the library.
- **Search Books**: Search for books by title, author, or ISBN.
- **User Management**: Register new users and manage user accounts.
- **Borrow and Return Books**: Users can borrow and return books.
- **Reservation System**: Implement a reservation system for books.

## Compatibility

Library Management System is compatible with:
- Linux
- MacOS

## Getting Started

### For Linux

1. Before running Minishell on Linux, ensure that you have the necessary dependencies installed. You may need to install the following packages:

   ```bash
   sudo apt-get update -y
   sudo apt-get install build-essential -y
   sudo apt-get install libreadline-dev -y
   ```

2. Clone the repository:

   ```bash
   git clone https://github.com/jesuismarie/library-management-system.git
   ```

3. Change into the project directory:

   ```bash
   cd Library-Management-System
   ```

4. Compile the program:

   ```bash
   make
   ```

5. Run MiniShell:

   ```bash
   ./library
   ```

6. You can now start managing books, users through the terminal interface.

### For MacOS

To get started with Library Management System, follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/jesuismarie/library-management-system.git
   ```

2. Change into the project directory:

   ```bash
   cd Library-Management-System
   ```

3. Configure Readline Library

   ```bash
   make configure
   ```

4. Compile the program:

   ```bash
   make
   ```

5. Run MiniShell:

   ```bash
   ./library
   ```

6. You can now start managing books, users through the terminal interface.

## Usage

Library Management System provides a command-line interface where you can manage library operations. Here are some examples:

- **Register a New User**:

  ```sh
  > REGISTER
  >> Enter username:
  >> Enter password:
  >> Re-enter password:
  ```

- **Login to Profile**:

  ```sh
  > LOGIN
  >> Enter username:
  >> Enter password:
  ```

  - **Logout from Profile**:

  ```sh
  > LOGIN
  >> Enter username:
  >> Enter password:
  ```

- **Add a New Book**:

  ```sh
  > ADD
  >> Enter title:
  >> Enter author:
  >> Enter isbn:
  ```

- **Remove a Book**:

  ```sh
  > REMOVE "1234567890"
  ```

- **Search for a Book**:

  ```sh
  > SEARCH
  >> Search:
  ```

- **Borrow a Book**:

  ```sh
  > BORROW
  >> Enter a book title or ISBN:
  ```

- **Return a Book**:

  ```sh
  > RETURN
  >> Enter a book title or ISBN:
  ```

## Project Structure

The project structure is as follows:

- `sources/`: Contains the source code files.
- `includes/`: Contains the header files.
- `Makefile`: The Makefile for compiling the project.


## Dependencies

MiniShell has the following dependencies:

- C compiler (e.g., CC)
- Make

## Contributing

We'd love to have you contribute! Please refer to our [contribution guidelines](./CONTRIBUTING.md) for details.

## License

This project is licensed under the Apache License - see the [LICENSE](./LICENSE) file for details.
