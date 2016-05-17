#include "edge.h"

int Edge::either() const {
    return v_;
}

double Edge::weigth() const {
    return weigth_;
}

int Edge::other(int vertex) const {
    return vertex == v_ ? w_ : v_;
}

int Edge::compare(const Edge that) const {
    if (weigth_ < that.weigth_) {
        return -1;
    }
    if (weigth_ > that.weigth_) {
        return +1;
    }
    return 0;
}
