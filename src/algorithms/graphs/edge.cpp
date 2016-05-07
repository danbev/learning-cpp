
class Edge {
    private:
        int v_;
        int w_;
        double weigth_;
    public:
        Edge(int v, int w, double weigth) : v_(v), w_(w), weigth_(weigth) {};
        double weigth() const;
        int either() const;
        int other(int vertex) const;
        int compare(const Edge that) const;
};

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
