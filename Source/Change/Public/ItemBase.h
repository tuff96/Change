// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Runtime/UMG/Public/Components/Image.h"
#include "ItemBase.generated.h"
/**
 * 
 */
UCLASS(BlueprintType,  Blueprintable)
class CHANGE_API UItemBase:public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* ItemTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubobjectPtr<UStaticMeshComponent> ItemForm;
};
