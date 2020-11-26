// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Order.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOrderDelegate);

UCLASS(BlueprintType,Blueprintable)
class PROJECTA_API UOrder : public UObject
{
	GENERATED_BODY()

		
public:
	UOrder();
	//创建一个命令对象
	UFUNCTION(BlueprintCallable, Category = "Order")
		static UOrder* CreateOrder();

	//UFUNCTION(BlueprintNativeEvent, Category = "Order")
	//	void OnFinish();
	//virtual void OnFinish_Implementation();

	//UFUNCTION(BlueprintNativeEvent, Category = "Order")
	//	void DoOrder();
	//virtual void DoOrder_Implementation();

	UFUNCTION(BlueprintCallable, Category = "Order")
		void StartOrder();

	UFUNCTION(BlueprintCallable, Category = "Order")
		void Finish();

	UPROPERTY(BlueprintAssignable)
		FOrderDelegate DoOrder;

	UPROPERTY(BlueprintAssignable)
		FOrderDelegate OnFinish;
	UPROPERTY(EditAnywhere)
		FString OrderKey;
	UFUNCTION(BlueprintCallable, Category = "Order")
		FString GetOrderKey();

	UFUNCTION(BlueprintCallable, Category = "Order")
		void SetOrderKey(FString key);
};
