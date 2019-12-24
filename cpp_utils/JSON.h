/*
 * JSON.h
 *
 *  Created on: May 23, 2017
 *      Author: kolban
 */

#ifndef COMPONENTS_CPP_UTILS_JSON_H_
#define COMPONENTS_CPP_UTILS_JSON_H_
#include <cJSON.h>
#include <string>
#include <vector>
#include <assert.h>
//#include "xstring.h"

// Forward declarations
class JsonObject;
class JsonArray;

/**
 * @brief Top level JSON handler.
 */

class JSON {
public:
	static JsonObject createObject();
	static JsonArray  createArray();
	static void       deleteObject(JsonObject jsonObject);
	static void       deleteArray(JsonArray jsonArray);
	static JsonObject parseObject(std::string text);
	static JsonArray  parseArray(std::string text);
}; // JSON


/**
 * @brief A JSON array.
 */
class JsonArray {
public:
//    XALLOCATOR

    JsonArray()
        : m_node(nullptr)
        , m_owner(true) {m_node = cJSON_CreateArray(); }
    
    JsonArray(JsonObject& obj); 
    
    ~JsonArray() {if (m_owner) cJSON_Delete(m_node); }

    int         getInt(int item) const;
    JsonObject  getObject(int item) const;
    std::string getString(int item) const;
    bool        getBoolean(int item) const;
    double      getDouble(int item) const;
    void        addBoolean(bool value);
    void        addDouble(double value);
    void        addInt(int value);
    void        addObject(JsonObject& value);
    void        addString(std::string value);
    std::string toString() const;
    std::string toStringUnformatted() const;
    void fromString(const std::string &string);

    std::size_t size() const;
private:
    JsonArray(cJSON* node, bool owner);
    friend class JSON;
    friend class JsonObject;
    /**
     * @brief The underlying cJSON node.
     */
    cJSON *m_node;
    bool m_owner;
}; // JsonArray


/**
 * @brief A JSON object.
 */
class JsonObject {
public:
    // over simplistic probably, but I wanted to add this destructor. May need to add reference counting.
    JsonObject()
        : m_node(nullptr)
        , m_owner(true) {m_node = cJSON_CreateObject(); }
//    XALLOCATOR

    JsonObject(const std::string& text);
    ~JsonObject() {if (m_owner) cJSON_Delete(m_node); }
    
    void takeOwnership(JsonObject &other) {
        assert(other.m_owner == true);
        other.m_owner = false;
        m_owner = true;
    }
    JsonArray   getArray(std::string name) const;
    bool        getBoolean(std::string name) const;
    double      getDouble(std::string name) const;
    int         getInt(std::string name) const;
    JsonObject  getObject(std::string name) const;
    std::string getString(std::string name) const;
    bool        hasItem(std::string name) const;
    bool        isBoolean() const {return cJSON_IsBool(m_node);}
    bool        isString() const {return cJSON_IsString(m_node);}
    bool        isNumber() const {return cJSON_IsNumber(m_node);}
    
    bool        isValid() const;
    void        setArray(std::string name, JsonArray& array);
    void        setBoolean(std::string name, bool value);
    void        setDouble(std::string name, double value);
    void        setInt(std::string name, int value);
    void        setObject(std::string name, JsonObject& value);
    void        setString(std::string name, std::string value);
    std::string toString() const;
    std::string toStringUnformatted() const;
    int getChildList(std::vector<std::string> &children) const;
    
//    xstring toXStringUnformatted() const;
    void        fromString(const std::string &string);

private:
    JsonObject(cJSON* node, bool owner);
    friend class JSON;
    friend class JsonArray;
    /**
     * @brief The underlying cJSON node.
     */
    cJSON* m_node;
    bool m_owner;
};  // JsonObject


#endif /* COMPONENTS_CPP_UTILS_JSON_H_ */
