/////////////////////////////////////////////
///COPYRIGHT NOTICE
/// Copyright (c) 2018
/// All rights reserved.
///
/// @file TJson.h
/// @brief 封装易用的json数据处理类
///
/// 底层实现源码来自于jsoncpp
///
/// @version 1.0
/// @author liukang
/// @date 2017.12.15
//////////////////////////////////////////////
#pragma once

#include <string>
#include <vector>

namespace WebTool {

class  TJson
{
public:

    /// @brief  获取传入的json是不是有效
    /// @param  obj 字符串json
    /// @return true 有效；false无效
    static bool isValid(const std::string obj);

    static std::string getStr(const std::string obj, const std::string sKey);
    static std::string getObj(const std::string obj, const std::string sKey);
    static int getInt(const std::string obj,  const std::string sKey);
    static std::vector<std::string> getArray(const std::string obj, const std::string sKey);

    static void setStr(std::string& obj, const std::string sKey,const std::string sValue);
    static void setObj(std::string& obj, const std::string sKey,const std::string sValue);
    static void setInt(std::string& obj, const std::string sKey,const int iValue);
    static void setArray(std::string& obj, const std::string sKey, const std::vector<std::string> array);
private:


};

} //namespace WebTool


