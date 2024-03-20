package com.QG;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;

public class JDBCTest {
    public static void main(String[] args) throws SQLException {
        Connection conn = JDBCUtils.getConnection();
        //
        String sql = "update user set name ='老w' where id = 3";
        //
        Statement stmt = conn.createStatement();
        //
        int count = stmt.executeUpdate(sql);
        //
        System.out.println(count);
        //
        JDBCUtils.close(stmt,conn);

    }
}
