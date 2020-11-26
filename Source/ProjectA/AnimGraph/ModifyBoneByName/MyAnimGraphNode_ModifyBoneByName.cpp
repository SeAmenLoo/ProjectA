// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimGraphNode_ModifyBoneByName.h"
#include "UnrealWidget.h"
#include "AnimNodeEditModes.h"
#include "Kismet2/CompilerResultsLog.h"

#define LOCTEXT_NAMESPACE "A3Nodes"
UMyAnimGraphNode_ModifyBoneByName::UMyAnimGraphNode_ModifyBoneByName(const FObjectInitializer& ObjectInitializer)
	
	: Super(ObjectInitializer)
{

	CurWidgetMode = (int32)FWidget::WM_Rotate;
}
FText UMyAnimGraphNode_ModifyBoneByName::GetControllerDescription() const
{

	return LOCTEXT("TransformModifyBoneByName", "Transform (Modify) BoneByName");
}


FText UMyAnimGraphNode_ModifyBoneByName::GetTooltipText() const
{
	return LOCTEXT("AnimGraphNode_ModifyBoneByName_Tooltip", "Theeeeee Transform Bone node alters the transform - i.e. Translation, Rotation, or Scale - of the bone");
}
FText UMyAnimGraphNode_ModifyBoneByName::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	if ((TitleType == ENodeTitleType::ListView || TitleType == ENodeTitleType::MenuTitle) && (Node.BoneToModify.BoneName == NAME_None))
	{
		return GetControllerDescription();
	}
	// @TODO: the bone can be altered in the property editor, so we have to 
	//        choose to mark this dirty when that happens for this to properly work
	else //if (!CachedNodeTitles.IsTitleCached(TitleType, this))
	{
		FFormatNamedArguments Args;
		Args.Add(TEXT("ControllerDescription"), GetControllerDescription());
		Args.Add(TEXT("BoneName"), FText::FromName(Node.BoneToModify.BoneName));

		// FText::Format() is slow, so we cache this to save on performance
		if (TitleType == ENodeTitleType::ListView || TitleType == ENodeTitleType::MenuTitle)
		{
			CachedNodeTitles.SetCachedTitle(TitleType, FText::Format(LOCTEXT("AnimGraphNode_ModifyBone_ListTitle", "{ControllerDescription} - Bone: {BoneName}"), Args), this);
		}
		else
		{
			CachedNodeTitles.SetCachedTitle(TitleType, FText::Format(LOCTEXT("AnimGraphNode_ModifyBone_Title", "{ControllerDescription}\nBone: {BoneName}"), Args), this);
		}
	}
	return CachedNodeTitles[TitleType];
}

void UMyAnimGraphNode_ModifyBoneByName::ValidateAnimNodeDuringCompilation(USkeleton* ForSkeleton, FCompilerResultsLog& MessageLog)
{
	// Temporary fix where skeleton is not fully loaded during AnimBP compilation and thus virtual bone name check is invalid UE-39499 (NEED FIX) 
	//if (ForSkeleton && !ForSkeleton->HasAnyFlags(RF_NeedPostLoad))
	//{
	//	if (ForSkeleton->GetReferenceSkeleton().FindBoneIndex(Node.BoneToModify.BoneName) == INDEX_NONE)
	//	{
	//		if (Node.BoneToModify.BoneName == NAME_None)
	//		{
	//			//MessageLog.Warning(*LOCTEXT("NoBoneSelectedToModify", "@@ - YYou must pick a bone to modify").ToString(), this);
	//		}
	//		else
	//		{
	//			FFormatNamedArguments Args;
	//			Args.Add(TEXT("BoneName"), FText::FromName(Node.BoneToModify.BoneName));

	//			FText Msg = FText::Format(LOCTEXT("NoBoneFoundToModify", "@@ - Bone {BoneName} not found in Skeleton"), Args);

	//			//MessageLog.Warning(*Msg.ToString(), this);
	//		}
	//	}
	//}

	//if ((Node.TranslationMode == MBMM_Ignore) && (Node.RotationMode == MBMM_Ignore) && (Node.ScaleMode == MBMM_Ignore))
	//{
	//	//MessageLog.Warning(*LOCTEXT("NothingToModify", "@@ - No components to modify selected.  Either Rotation, Translation, or Scale should be set to something other than Ignore").ToString(), this);
	//}

	//Super::ValidateAnimNodeDuringCompilation(ForSkeleton, MessageLog);
}

//
//void UMyAnimGraphNode_ModifyBoneByName::CopyNodeDataToPreviewNode(FAnimNode_Base* InPreviewNode)
//{
//	FMyAnimNode_ModifyBoneByName* ModifyBone = static_cast<FMyAnimNode_ModifyBoneByName*>(InPreviewNode);
//
//	// copies Pin values from the internal node to get data which are not compiled yet
//	ModifyBone->Translation = Node.Translation;
//	ModifyBone->Rotation = Node.Rotation;
//	ModifyBone->Scale = Node.Scale;
//
//	// copies Modes
//	ModifyBone->TranslationMode = Node.TranslationMode;
//	ModifyBone->RotationMode = Node.RotationMode;
//	ModifyBone->ScaleMode = Node.ScaleMode;
//
//	// copies Spaces
//	ModifyBone->TranslationSpace = Node.TranslationSpace;
//	ModifyBone->RotationSpace = Node.RotationSpace;
//	ModifyBone->ScaleSpace = Node.ScaleSpace;
//}
//FEditorModeID UMyAnimGraphNode_ModifyBoneByName::GetEditorMode() const
//{
//	return AnimNodeEditModes::ModifyBone;
//}
//
//void UMyAnimGraphNode_ModifyBoneByName::CopyPinDefaultsToNodeData(UEdGraphPin* InPin)
//{
//	if (InPin->GetName() == GET_MEMBER_NAME_STRING_CHECKED(FMyAnimNode_ModifyBoneByName, Translation))
//	{
//		GetDefaultValue(GET_MEMBER_NAME_STRING_CHECKED(FMyAnimNode_ModifyBoneByName, Translation), Node.Translation);
//	}
//	else if (InPin->GetName() == GET_MEMBER_NAME_STRING_CHECKED(FMyAnimNode_ModifyBoneByName, Rotation))
//	{
//		GetDefaultValue(GET_MEMBER_NAME_STRING_CHECKED(FMyAnimNode_ModifyBoneByName, Rotation), Node.Rotation);
//	}
//	else if (InPin->GetName() == GET_MEMBER_NAME_STRING_CHECKED(FMyAnimNode_ModifyBoneByName, Scale))
//	{
//		GetDefaultValue(GET_MEMBER_NAME_STRING_CHECKED(FMyAnimNode_ModifyBoneByName, Scale), Node.Scale);
//	}
//}
#undef LOCTEXT_NAMESPACE