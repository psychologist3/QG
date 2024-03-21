package com.QG;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

public class JDBCDemo {


    public static void main(String[] args) throws Exception {
        //1.注册驱动
        //2.获取链接
        String url ="jdbc:mysql://127.0.0.1:3306/test";
        String username = "root";
        String password ="123456";
        Connection conn = DriverManager.getConnection(url,username,password);

        //3.定义sql语句
        String sql = "update user set name = ? where id = ?;";

        //4.获取执行sql的对象Statement
        PreparedStatement preparestatement = conn.prepareStatement(sql);

        preparestatement.setInt(2,1);
        preparestatement.setString(1,"老三");

        //5.执行sql
        int count = preparestatement.executeUpdate();

        //6.处理结果
        System.out.println(count);

        //释放资源

        preparestatement.close();
        conn.close();

    }
}
