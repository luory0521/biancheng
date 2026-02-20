#include <iostream>
#include <vector>
#include <cmath>

// 使用标准命名空间
using namespace std;

// 定义质点结构体
struct Particle {
    double x, y;  // 位置
    double vx, vy; // 速度
    double mass;  // 质量
};

// 计算两个质点之间的引力
void calculateGravitationalForce(const Particle& p1, const Particle& p2, double& fx, double& fy) {
    const double G = 1.0; // 引力常数
    const double minDistance = 0.001; // 最小距离
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double r = std::sqrt(dx * dx + dy * dy);
    if (r < minDistance) {
        r = minDistance; // 避免距离过近导致除零错误
    }
    double force = G * p1.mass * p2.mass / (r * r);
    fx = force * dx / r;
    fy = force * dy / r;
}

// 更新质点的位置和速度
void updateParticles(vector<Particle>& particles, double dt, double boundaryX, double boundaryY) {
    vector<double> fx(particles.size(), 0.0);
    vector<double> fy(particles.size(), 0.0);

    // 计算所有质点之间的引力
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

    // 更新质点的位置和速度
    for (size_t i = 0; i < particles.size(); ++i) {
        double ax = fx[i] / particles[i].mass;
        double ay = fy[i] / particles[i].mass;
        particles[i].vx += ax * dt;
        particles[i].vy += ay * dt;
        particles[i].x += particles[i].vx * dt;
        particles[i].y += particles[i].vy * dt;

        // 边界反弹
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

    const int numSteps = 1000;
    const double dt = 0.01;
    const double boundaryX = 100.0;
    const double boundaryY = 100.0;

    // 模拟运动
    for (int step = 0; step < numSteps; ++step) {
        updateParticles(particles, dt, boundaryX, boundaryY);

        // 输出每个质点的位置
        for (size_t i = 0; i < particles.size(); ++i) {
            cout << "Step " << step << ", Particle " << i << ": (" << particles[i].x << ", " << particles[i].y << ")" << endl;
        }
    }

    return 0;
}
