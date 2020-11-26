// Fill out your copyright notice in the Description page of Project Settings.


#include "Order.h"

UOrder::UOrder()
{
}

UOrder* UOrder::CreateOrder() {		
	return NewObject<UOrder>();
}

void UOrder::StartOrder() {
	DoOrder.Broadcast();
}

void UOrder::Finish() {
	OnFinish.Broadcast();
}
FString UOrder::GetOrderKey() {
	return OrderKey;
}
void UOrder::SetOrderKey(FString key) {
	OrderKey = key;
}