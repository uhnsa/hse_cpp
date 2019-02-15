#include <vector>

template <typename T>
class Table {
private:
    using Row = std::vector<T>;
    std::vector<Row> data_;
    size_t row_{0};
    size_t column_{0};

public:
    Table() = default;

    Table(size_t row, size_t column)
    : row_{row}, column_{column} {
        data_.resize(row);
        for (size_t i = 0; i < row; ++i) {
            data_[i].resize(column);
        }
    }

    void resize(size_t row, size_t column) {
        row_ = row;
        column_ = column;
        data_.resize(row);
        for (size_t i = 0; i < row; ++i) {
            data_[i].resize(column);
        }
    }

    const std::pair<size_t, size_t> size() const {
        return {row_, column_};
    }

    const Row& operator[] (size_t i) const {
        return data_[i];
    }

    Row& operator[] (size_t i) {
        return data_[i];
    }
};
