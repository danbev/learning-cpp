#ifndef EDGE_H
#define EDGE_H
class Edge {
    private:
        int v_;
        int w_;
        double weight_;
    public:
        Edge(int v, int w, double weight);
        double weight() const;
        int either() const;
        int other(int vertex) const;
        int compare(const Edge that) const;
};
#endif
