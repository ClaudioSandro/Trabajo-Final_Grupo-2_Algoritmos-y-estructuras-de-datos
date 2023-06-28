#pragma once
#include <iostream>
#include <vector>
#include <functional>

struct USCON {
    std::string usuario;
    std::string contrasena;

    bool operator==(const USCON& other) const {
        return (usuario == other.usuario && contrasena == other.contrasena);
    }
};


namespace std {
    template <>
    struct hash<USCON> {
        std::size_t operator()(const USCON& uscon) const {
            std::size_t hash = 0;
            hash_combine(hash, std::hash<std::string>{}(uscon.usuario));
            hash_combine(hash, std::hash<std::string>{}(uscon.contrasena));
            return hash;
        }

        // Función auxiliar para combinar múltiples hashes
        template <typename T>
        void hash_combine(std::size_t& seed, const T& value) const {
            seed ^= std::hash<T>{}(value)+0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
    };
}


template<typename KeyType, typename ValueType>
class HashTable {
private:
    struct Node {
        KeyType key;
        ValueType data;
        Node* next;

        Node(const KeyType& k, const ValueType& d) : key(k), data(d), next(nullptr) {}
    };

    std::vector<Node*> buckets;
    size_t numBuckets;

    size_t hashFunction(const KeyType& key) const {
        // Función de hash básica para obtener el índice del bucket
        // Puedes implementar una función de hash más sofisticada si lo deseas
        return (std::hash<KeyType>{}(key) % numBuckets);
    }

public:
    HashTable(size_t size) : numBuckets(size) {
        // Inicializa los buckets con nullptr
        buckets.resize(numBuckets, nullptr);
    }

    ~HashTable() {
        // Libera la memoria de los nodos
        for (size_t i = 0; i < numBuckets; ++i) {
            Node* current = buckets[i];
            while (current) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

    void insert(const KeyType& key, const ValueType& data) {
        size_t index = hashFunction(key);

        Node* newNode = new Node(key, data);
        if (!buckets[index]) {
            // El bucket está vacío, inserta el nuevo nodo directamente
            buckets[index] = newNode;
        }
        else {
            // El bucket no está vacío, agrega el nuevo nodo al principio
            newNode->next = buckets[index];
            buckets[index] = newNode;
        }
    }

    bool search(const KeyType& key, ValueType& data) const {
        size_t index = hashFunction(key);

        Node* current = buckets[index];
        while (current) {
            if (current->key == key) {
                data = current->data;
                return true;  // Elemento encontrado
            }
            current = current->next;
        }

        return false;  // Elemento no encontrado
    }

    bool getData(const KeyType& key, ValueType& data) const {
        return search(key, data);
    }
};
