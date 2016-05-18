#include "edge.h"

Edge::Edge(int v, int w, double weight) : v_(v), w_(w), weight_(weight) {
}

int Edge::either() const {
    return v_;
}

double Edge::weight() const {
    return weight_;
}

int Edge::other(int vertex) const {
    return vertex == v_ ? w_ : v_;
}

int Edge::compare(const Edge that) const {
    if (weight_ < that.weight_) {
        return -1;
    }
    if (weight_ > that.weight_) {
        return +1;
    }
    return 0;
}
