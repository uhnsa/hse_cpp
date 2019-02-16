#include <vector>

template <typename T>
class Table {
public:
    using Row = std::vector<T>;

    Table(size_t row_count, size_t column_count) {
        data_.resize(row_count);
        for (size_t i = 0; i < row_count; ++i) {
            data_[i].resize(column_count);
        }
    }

    void resize(size_t row_count, size_t column_count) {
        data_.resize(row_count);
        for (size_t i = 0; i < row_count; ++i) {
            data_[i].resize(column_count);
        }
    }

    const std::pair<size_t, size_t> size() const {
        return {data_.size(), data_.front().size()};
    }

    const Row& operator[] (size_t i) const {
        return data_[i];
    }

    Row& operator[] (size_t i) {
        return data_[i];
    }

private:
    std::vector<Row> data_;
};
