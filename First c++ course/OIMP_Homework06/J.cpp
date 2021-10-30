//#include <iostream>
//#include <memory>
//#include <string>
//
//class Expression {
//public:
//    virtual int Evaluate() const = 0;
//    virtual std::string ToString() const = 0;
//    virtual ~Expression() {}
//};
//
//using ExpressionPtr = std::shared_ptr<Expression>;
//
//#include <memory>
//#include <string>
//#include <unordered_map>
//
//std::unordered_map<Expression*, bool> is_sum;
//
//class ConstExpression: public Expression {
//private:
//    const int val;
//
//public:
//    ConstExpression(int _val) : val(_val) {
//        is_sum[this] = false;
//    }
//    int Evaluate() const override {
//        return val;
//    }
//    std::string ToString() const override {
//        return std::to_string(val);
//    }
//    ~ConstExpression() {}
//};
//
//class SumExpression: public Expression {
//private:
//    ExpressionPtr left, right;
//
//public:
//    SumExpression(ExpressionPtr _left, ExpressionPtr _right) : left(_left), right(_right) {
//        is_sum[this] = true;
//    }
//    int Evaluate() const override {
//        return left->Evaluate() + right->Evaluate();
//    }
//    std::string ToString() const override {
//        auto left_s = left->ToString();
//        auto right_s = right->ToString();
//        return left_s + " + " + right_s;
//    }
//};
//
//class ProductExpression: public Expression {
//private:
//    ExpressionPtr left, right;
//
//public:
//    ProductExpression(ExpressionPtr _left, ExpressionPtr _right) : left(_left), right(_right) {
//        is_sum[this] = false;
//    }
//    int Evaluate() const override {
//        return left->Evaluate() * right->Evaluate();
//    }
//    std::string ToString() const override {
//        std::string res;
//        auto left_s = left->ToString();
//        if (is_sum[left.get()]) {
//            res = "(" + left_s + ")";
//        } else {
//            res = left_s;
//        }
//        res += " * ";
//        auto right_s = right->ToString();
//        if (is_sum[right.get()]) {
//            res += "(" + right_s + ")";
//        } else {
//            res += right_s;
//        }
//        return res;
//    }
//};
//
//
//ExpressionPtr Const(int val) {
//    ExpressionPtr res(new ConstExpression(val));
//    return res;
//}
//
//ExpressionPtr Sum(ExpressionPtr left, ExpressionPtr right) {
//    ExpressionPtr res(new SumExpression(left, right));
//    return res;
//}
//
//ExpressionPtr Product(ExpressionPtr left, ExpressionPtr right) {
//    ExpressionPtr res(new ProductExpression(left, right));
//    return res;
//}
//
//
//int main() {
//    ExpressionPtr ex1 = Sum(Product(Const(3), Const(4)), Const(5));
//    std::cout << ex1->ToString() << "\n";  // 3 * 4 + 5
//    std::cout << ex1->Evaluate() << "\n";  // 17
//
//    ExpressionPtr ex2 = Product(Const(6), ex1);
//    std::cout << ex2->ToString() << "\n";  // 6 * (3 * 4 + 5)
//    std::cout << ex2->Evaluate() << "\n";  // 102
//}