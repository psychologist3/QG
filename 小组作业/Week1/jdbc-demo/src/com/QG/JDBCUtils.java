package com.QG;

import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class JDBCUtils {
    public static String driver;
    public static String url;
    public static String password;
    public static String username;

    static {
        InputStream asStream=JDBCUtils.class.getResourceAsStream("/jdbc.properties");
        Properties p =new Properties();
        try {
            p.load(asStream);
            driver=p.getProperty("driver");
            url=p.getProperty("url");
            username=p.getProperty("username");
            password=p.getProperty("password");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
    public static Connection getConnection() {
        Connection conn = null;
        try {
            conn = DriverManager.getConnection(url,username,password);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return conn;
    }

    public static  void close(Statement statement, Connection connection){
        try {
            statement.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        try {
            connection.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}

