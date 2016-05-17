#ifndef EDGE_H
#define EDGE_H
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
#endif
