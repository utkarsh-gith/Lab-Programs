import java.sql.*;
import java.util.Scanner;

public class lab10 {
    // JDBC URL, username, and password of MySQL server
    private static final String JDBC_URL = "jdbc:mysql://localhost:3306/students";
    private static final String DB_USER = "root";
    private static final String DB_PASSWORD = "";

    public static void main(String[] args) {
        // Establishing a Connection
        try (Connection connection = DriverManager.getConnection(JDBC_URL, DB_USER, DB_PASSWORD)) {
            Scanner scanner = new Scanner(System.in);
            boolean continueProgram = true;

            while (continueProgram) {
                // Displaying the Menu
                System.out.println("\nMenu:");
                System.out.println("1. Create Record");
                System.out.println("2. Read Records");
                System.out.println("3. Update Record");
                System.out.println("4. Delete Record");
                System.out.println("5. Exit");
                System.out.print("Enter your choice: ");
                
                int choice;
                try {
                    choice = scanner.nextInt();
                } catch (Exception e) {
                    System.out.println("Invalid input. Please enter a number between 1 and 5.");
                    scanner.nextLine(); // clear the buffer
                    continue;
                }

                scanner.nextLine(); // consume the newline
                switch (choice) {
                    case 1 -> createRecord(connection, scanner);
                    case 2 -> readRecords(connection);
                    case 3 -> updateRecord(connection, scanner);
                    case 4 -> deleteRecord(connection, scanner);
                    case 5 -> {
                        System.out.println("Exiting program.");
                        continueProgram = false;
                    }
                    default -> System.out.println("Invalid choice! Please select a valid option.");
                }
            }

            scanner.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void createRecord(Connection connection, Scanner scanner) {
        try {
            System.out.print("Enter ID: ");
            int id = scanner.nextInt();
            scanner.nextLine(); // consume the newline
            System.out.print("Enter Name: ");
            String name = scanner.nextLine();
            System.out.print("Enter USN: ");
            int usn = scanner.nextInt();
            System.out.print("Enter Semester: ");
            int semester = scanner.nextInt();
            System.out.print("Enter Age: ");
            int age = scanner.nextInt();
            scanner.nextLine(); // consume the newline
            System.out.print("Enter Course: ");
            String course = scanner.nextLine();
            System.out.print("Enter DOB (YYYY-MM-DD): ");
            String dob = scanner.nextLine();
            System.out.print("Enter Address: ");
            String address = scanner.nextLine();

            String createQuery = "INSERT INTO students (id, name, usn, semester, age, course, dob, address) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
            try (PreparedStatement preparedStatement = connection.prepareStatement(createQuery)) {
                preparedStatement.setInt(1, id);
                preparedStatement.setString(2, name);
                preparedStatement.setInt(3, usn);
                preparedStatement.setInt(4, semester);
                preparedStatement.setInt(5, age);
                preparedStatement.setString(6, course);
                preparedStatement.setString(7, dob);
                preparedStatement.setString(8, address);
                preparedStatement.executeUpdate();
                System.out.println("Record created successfully.");
            }
        } catch (SQLException e) {
            System.out.println("Error creating record: " + e.getMessage());
        }
    }

    private static void readRecords(Connection connection) {
        String readQuery = "SELECT * FROM students";
        try (Statement statement = connection.createStatement();
             ResultSet resultSet = statement.executeQuery(readQuery)) {
            System.out.println("\nAll Student Records:");
            while (resultSet.next()) {
                displayRecord(resultSet);
            }
        } catch (SQLException e) {
            System.out.println("Error reading records: " + e.getMessage());
        }
    }

    private static void updateRecord(Connection connection, Scanner scanner) {
        try {
            System.out.print("Enter the ID of the student to update: ");
            int idToUpdate = scanner.nextInt();
            System.out.print("Enter the new age: ");
            int newAge = scanner.nextInt();

            String updateQuery = "UPDATE students SET age = ? WHERE id = ?";
            try (PreparedStatement preparedStatement = connection.prepareStatement(updateQuery)) {
                preparedStatement.setInt(1, newAge);
                preparedStatement.setInt(2, idToUpdate);
                int rowsAffected = preparedStatement.executeUpdate();
                if (rowsAffected > 0) {
                    System.out.println("Record updated successfully.");
                } else {
                    System.out.println("No record found with ID " + idToUpdate);
                }
            }
        } catch (SQLException e) {
            System.out.println("Error updating record: " + e.getMessage());
        }
    }

    private static void deleteRecord(Connection connection, Scanner scanner) {
        try {
            System.out.print("Enter the ID of the student to delete: ");
            int idToDelete = scanner.nextInt();

            String deleteQuery = "DELETE FROM students WHERE id = ?";
            try (PreparedStatement preparedStatement = connection.prepareStatement(deleteQuery)) {
                preparedStatement.setInt(1, idToDelete);
                int rowsAffected = preparedStatement.executeUpdate();
                if (rowsAffected > 0) {
                    System.out.println("Record deleted successfully.");
                } else {
                    System.out.println("No record found with ID " + idToDelete);
                }
            }
        } catch (SQLException e) {
            System.out.println("Error deleting record: " + e.getMessage());
        }
    }

    private static void displayRecord(ResultSet resultSet) throws SQLException {
        int id = resultSet.getInt("id");
        String name = resultSet.getString("name");
        int usn = resultSet.getInt("usn");
        int semester = resultSet.getInt("semester");
        int age = resultSet.getInt("age");
        String course = resultSet.getString("course");
        String dob = resultSet.getString("dob");
        String address = resultSet.getString("address");

        System.out.println("ID: " + id + ", Name: " + name + ", USN: " + usn +
                ", Semester: " + semester + ", Age: " + age + ", Course: " + course +
                ", DOB: " + dob + ", Address: " + address);
    }
}
