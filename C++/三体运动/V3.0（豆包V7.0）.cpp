#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Particle {
    double x, y;
    double vx, vy;
    double mass;
};

void calculateGravitationalForce(const Particle& p1, const Particle& p2, double& fx, double& fy) {
    const double G = 1.0;
    const double minDistance = 0.001;
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double r = std::sqrt(dx * dx + dy * dy);
    if (r < minDistance) {
        r = minDistance;
    }
    double force = G * p1.mass * p2.mass / (r * r);
    fx = force * dx / r;
    fy = force * dy / r;
}

void updateParticles(vector<Particle>& particles, double dt, double boundaryX, double boundaryY) {
    vector<double> fx(particles.size(), 0.0);
    vector<double> fy(particles.size(), 0.0);

    for (size_t i = 0; i < particles.size(); ++i) {
        for (size_t j = i + 1; j < particles.size(); ++j) {
            double fxi, fyi;
            calculateGravitationalForce(particles[i], particles[j], fxi, fyi);
            fx[i] += fxi;
            fy[i] += fyi;
            fx[j] -= fxi;
            fy[j] -= fyi;
        }
    }

    for (size_t i = 0; i < particles.size(); ++i) {
        double ax = fx[i] / particles[i].mass;
        double ay = fy[i] / particles[i].mass;
        particles[i].vx += ax * dt;
        particles[i].vy += ay * dt;
        particles[i].x += particles[i].vx * dt;
        particles[i].y += particles[i].vy * dt;

        if (particles[i].x < 0 || particles[i].x > boundaryX) {
            particles[i].vx = -particles[i].vx;
            if (particles[i].x < 0) particles[i].x = 0;
            if (particles[i].x > boundaryX) particles[i].x = boundaryX;
        }
        if (particles[i].y < 0 || particles[i].y > boundaryY) {
            particles[i].vy = -particles[i].vy;
            if (particles[i].y < 0) particles[i].y = 0;
            if (particles[i].y > boundaryY) particles[i].y = boundaryY;
        }
    }
}

int main() {
    int numParticles;
    cout << "请输入质点数: ";
    cin >> numParticles;

    vector<Particle> particles(numParticles);

    for (int i = 0; i < numParticles; ++i) {
        cout << "请输入第 " << i + 1 << " 个质点的 x 位置, y 位置, x 方向速度, y 方向速度, 质量 (用空格分隔): ";
        cin >> particles[i].x >> particles[i].y >> particles[i].vx >> particles[i].vy >> particles[i].mass;
    }

    int numSteps;
    cout << "请输入模拟步数: ";
    cin >> numSteps;

    const double dt = 0.01;
    const double boundaryX = 800.0;
    const double boundaryY = 600.0;

    for (int step = 0; step < numSteps; ++step) {
        updateParticles(particles, dt, boundaryX, boundaryY);

        // 输出每个质点的位置
        for (size_t i = 0; i < particles.size(); ++i) {
            cout << "第 " << step + 1 << " 步, 质点 " << i + 1 << ": (" << particles[i].x << ", " << particles[i].y << ")" << endl;
        }
    }

    return 0;
}    
