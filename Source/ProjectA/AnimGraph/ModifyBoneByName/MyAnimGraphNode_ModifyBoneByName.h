// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


//#include "AnimGraphNode_ModifyBone.h"

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "MyAnimNode_ModifyBoneByName.h"
#include "EdGraph/EdGraphNodeUtils.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "MyAnimGraphNode_ModifyBoneByName.generated.h"
/**
 * 
 */
class FCompilerResultsLog;
UCLASS(meta = (Keywords = "Modify Transform By Name"))
class PROJECTA_API UMyAnimGraphNode_ModifyBoneByName : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_UCLASS_BODY()
	UPROPERTY(EditAnywhere, Category = Settings)
	FMyAnimNode_ModifyBoneByName Node;
public:
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;
protected:
	// UAnimGraphNode_Base interface
	virtual void ValidateAnimNodeDuringCompilation(USkeleton* ForSkeleton, FCompilerResultsLog& MessageLog) override;
	/*virtual FEditorModeID GetEditorMode() const override;
	virtual void CopyNodeDataToPreviewNode(FAnimNode_Base* InPreviewNode) override;
	virtual void CopyPinDefaultsToNodeData(UEdGraphPin* InPin) override;*/
	// End of UAnimGraphNode_Base interface
	virtual FText GetControllerDescription() const override;
	virtual const FAnimNode_SkeletalControlBase* GetNode() const override { return &Node; }

private:
	/** Constructing FText strings can be costly, so we cache the node's title */
	FNodeTitleTextTable CachedNodeTitles;
	int32 CurWidgetMode;

};
