#ifndef __RECEIEVETURN_H
#define __RECEIEVETURN_H

void turn_charinto_float(unsigned char* p, float* zz); //p[]为nrf24l01 接收到的数据，xx1,yy1,zz1 用于存储 pitch，roll，yaw 的各个位; zz 用于存储float类型的数据

#endif
