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
    private static String table;
    private static String field1;

    public static String getTable() {
        return table;
    }

    public static void setTable(String table) {
        JDBCUtils.table = table;
    }

    public String getField() {
        return field1;
    }

    public static void setField(String field) {
        field1 = field;
    }

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

    //释放资源
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

    //添加字段
    public static void addField(String type, String comment) throws Exception {
        //定义sql语句
        String sql;
        if(comment!=null) {
            sql = "alter table " + table + " add " + field1 + " " + type + " comment '" + comment + "'";
        }else {
            sql = "alter table " + table + " add " + field1 + " " + type;
        }
        SQL(sql);
    }
    public static void addField(String field, String type, String comment) throws Exception {
        setField(field);
        addField(type,comment);
    }
    public static void addField(String table,String field,String type,String comment) throws Exception {
        setTable(table);
        addField(field,type,comment);
    }

    //修改数据类型
    public static void modifyField(String type,String comment) throws Exception {
        String sql;
        if(comment!=null) {
            sql = "alter table " + table + " modify " + field1 + " " + type + " comment '" + comment + "'";
        }else {
            sql = "alter table " + table + " modify " + field1 + " " + type;
        }
        SQL(sql);
    }
    public static void modifyField(String field,String type,String comment) throws Exception {
        setField(field);
        modifyField(type,comment);
    }
    public static void modifyField(String table,String field,String type,String comment) throws Exception{
        setTable(table);
        modifyField(field,type,comment);
    }

    //修改字段名和字段类型
    public static void changeField(String oldField,String newField,String type,String comment) throws Exception {
        String sql;
        if(comment!=null){
            sql = "alter table "+table+" change "+oldField+" "+newField+" "+type+" comment '"+comment+"'";
        }else {
            sql = "alter table "+table+" change "+oldField+" "+newField+" "+type;
        }
        SQL(sql);
    }
    public static void changeField(String table ,String oldField,String newField,String type,String comment) throws Exception {
        setTable(table);
        changeField(oldField,newField,type,comment);

    }


    //删除字段
    public static void deleteField(String field) throws Exception {
        String sql ="alter table "+table+" drop "+field;
        SQL(sql);
    }
    public static void deleteField(String table,String field) throws Exception {
        setTable(table);
        deleteField(field);
    }

    //修改表名
    public static void changeTable(String oldTable,String newTable) throws Exception {
        String sql = "alter table "+oldTable+" rename to "+newTable;
        SQL(sql);
    }

    //
    public static void deleteTable(String table) throws Exception {
        String sql = "drop table if exists "+table;
        SQL(sql);
    }

    public static void update(String table,String field,String content){

    }

    public static void SQL(String sql) throws ClassNotFoundException, Exception {
        //获取连接
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

