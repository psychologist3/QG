package com.QG;

import java.io.IOException;
import java.io.InputStream;
import java.sql.*;
import java.util.Properties;

public class JDBCUtils {
    public static String driver;
    public static String url;
    public static String password;
    public static String username;
    static {
        try {
            Class.forName("com.mysql.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
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
    //获取连接
    public static Connection getConnection() {
        Connection conn = null;
        try {
            conn = DriverManager.getConnection(url,username,password);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return conn;
    }

    public static  void close(ResultSet rs,Statement statement, Connection connection){
        if(rs!=null) {
            try {
                rs.close();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
        if(statement !=null) {
            try {
                statement.close();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
        if(connection!=null){
            try {
                connection.close();
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
    }


    public static void SQL(String sql) throws ClassNotFoundException, Exception {
        //
        Connection conn = JDBCUtils.getConnection();
        //
        Statement stmt = conn.createStatement();
        //
        int count = stmt.executeUpdate(sql);
        //
        System.out.println(count);
        //
        JDBCUtils.close(null,stmt ,conn);

    }

}

