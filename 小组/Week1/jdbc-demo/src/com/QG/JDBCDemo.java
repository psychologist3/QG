package com.QG;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class JDBCDemo {


    public static void main(String[] args) throws Exception {
        //1.注册驱动
        //2.获取链接
        String url ="jdbc:mysql://127.0.0.1:3306/test";
        String username = "root";
        String password ="123456";
        Connection conn = DriverManager.getConnection(url,username,password);

        //3.定义sql语句
        String sql = "update user set name ='老头' where id = 3;";

        //4.获取执行sql的对象Statement
        Statement stmt = conn.createStatement();

        //5.执行sql
        int count = stmt.executeUpdate(sql);

        //6.处理结果
        System.out.println(count);

        //释放资源

        stmt.close();
        conn.close();

    }
}
