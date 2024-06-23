///////////////////////////////////////////////////////////
// Yoga
///////////////////////////////////////////////////////////

// Workaround to avoid exporting Yoga symbols
#include <yoga/YGMacros.h>
#undef YG_EXPORT
#define YG_EXPORT

#include <yoga/YGConfig.cpp>
#include <yoga/YGEnums.cpp>
#include <yoga/YGNode.cpp>
#include <yoga/YGNodeLayout.cpp>
#include <yoga/YGNodeStyle.cpp>
#include <yoga/YGPixelGrid.cpp>
#include <yoga/YGValue.cpp>

#include <yoga/algorithm/AbsoluteLayout.cpp>
#include <yoga/algorithm/Baseline.cpp>
#include <yoga/algorithm/Cache.cpp>
#include <yoga/algorithm/CalculateLayout.cpp>
#include <yoga/algorithm/FlexLine.cpp>
#include <yoga/algorithm/PixelGrid.cpp>

#include <yoga/config/Config.cpp>

#include <yoga/debug/AssertFatal.cpp>
#include <yoga/debug/Log.cpp>

#include <yoga/node/LayoutResults.cpp>
#include <yoga/node/Node.cpp>

// Workaround for ambiguous 'Node' definition
#define Node _Node
#include <yoga/event/event.cpp>
#undef Node

///////////////////////////////////////////////////////////
// Flex UI
///////////////////////////////////////////////////////////
#define EXPORT __attribute__((visibility("default")))

#include <stdexcept>

extern "C"
{

	EXPORT YGConfigRef FlexUi_ConfigNew()
	{
		return YGConfigNew();
	}

	EXPORT void FlexUi_ConfigFree(YGConfigRef config)
	{
		YGConfigFree(config);
	}

	EXPORT YGConfigConstRef FlexUi_ConfigGetDefault()
	{
		return YGConfigGetDefault();
	}

	EXPORT void FlexUi_ConfigSetUseWebDefaults(YGConfigRef config, bool enabled)
	{
		YGConfigSetUseWebDefaults(config, enabled);
	}

	EXPORT bool FlexUi_ConfigGetUseWebDefaults(YGConfigConstRef config)
	{
		return YGConfigGetUseWebDefaults(config);
	}

	EXPORT void FlexUi_ConfigSetPointScaleFactor(YGConfigRef config, float pixelsInPoint)
	{
		YGConfigSetPointScaleFactor(config, pixelsInPoint);
	}

	EXPORT float FlexUi_ConfigGetPointScaleFactor(YGConfigConstRef config)
	{
		return YGConfigGetPointScaleFactor(config);
	}

	EXPORT void FlexUi_ConfigSetErrata(YGConfigRef config, YGErrata errata)
	{
		YGConfigSetErrata(config, errata);
	}

	EXPORT void FlexUi_ConfigSetLogger(YGConfigRef config, YGLogger logger)
	{
		YGConfigSetLogger(config, logger);
	}

	EXPORT void FlexUi_ConfigSetContext(YGConfigRef config, void *context)
	{
		YGConfigSetContext(config, context);
	}

	EXPORT void *FlexUi_ConfigGetContext(YGConfigConstRef config)
	{
		return YGConfigGetContext(config);
	}

	EXPORT void FlexUi_ConfigSetExperimentalFeatureEnabled(YGConfigRef config, YGExperimentalFeature feature, bool enabled)
	{
		YGConfigSetExperimentalFeatureEnabled(config, feature, enabled);
	}

	EXPORT bool FlexUi_ConfigIsExperimentalFeatureEnabled(YGConfigConstRef config, YGExperimentalFeature feature)
	{
		return YGConfigIsExperimentalFeatureEnabled(config, feature);
	}

	EXPORT void FlexUi_CYGConfigSetCloneNodeFunc(YGConfigRef config, YGCloneNodeFunc callback)
	{
		YGConfigSetCloneNodeFunc(config, callback);
	}

	EXPORT YGNodeRef FlexUi_NodeNew()
	{
		return YGNodeNew();
	}

	EXPORT YGNodeRef FlexUi_NodeNewWithConfig(YGConfigConstRef config)
	{
		return YGNodeNewWithConfig(config);
	}

	EXPORT YGNodeRef FlexUi_NodeClone(YGNodeConstRef node)
	{
		return YGNodeClone(node);
	}

	EXPORT void FlexUi_NodeFree(YGNodeRef node)
	{
		YGNodeFree(node);
	}

	EXPORT void FlexUi_NodeFreeRecursive(YGNodeRef node)
	{
		YGNodeFreeRecursive(node);
	}

	EXPORT void FlexUi_NodeFinalize(YGNodeRef node)
	{
		YGNodeFinalize(node);
	}

	EXPORT void FlexUi_YYGNodeReset(YGNodeRef node)
	{
		YGNodeReset(node);
	}

	EXPORT void FlexUi_NodeCalculateLayout(YGNodeRef node, float availableWidth, float availableHeight, YGDirection ownerDirection)
	{
		YGNodeCalculateLayout(node, availableWidth, availableHeight, ownerDirection);
	}

	EXPORT bool FlexUi_NodeGetHasNewLayout(YGNodeConstRef node)
	{
		return YGNodeGetHasNewLayout(node);
	}

	EXPORT void FlexUi_NodeSetHasNewLayout(YGNodeRef node, bool hasNewLayout)
	{
		YGNodeSetHasNewLayout(node, hasNewLayout);
	}

	EXPORT bool FlexUi_NodeIsDirty(YGNodeConstRef node)
	{
		return YGNodeIsDirty(node);
	}

	EXPORT void FlexUi_NodeMarkDirty(YGNodeRef node)
	{
		YGNodeMarkDirty(node);
	}

	EXPORT void FlexUi_NodeSetDirtiedFunc(YGNodeRef node, YGDirtiedFunc dirtiedFunc)
	{
		YGNodeSetDirtiedFunc(node, dirtiedFunc);
	}

	EXPORT YGDirtiedFunc FlexUi_NodeGetDirtiedFunc(YGNodeConstRef node)
	{
		return YGNodeGetDirtiedFunc(node);
	}

	EXPORT const char *FlexUi_NodeInsertChild(YGNodeRef node, YGNodeRef child, int index)
	{
		try
		{
			YGNodeInsertChild(node, child, index);
			return NULL;
		}
		catch (std::logic_error err)
		{
			return strdup(err.what());
		}
	}

	EXPORT void FlexUi_NodeSwapChild(YGNodeRef node, YGNodeRef child, size_t index)
	{
		YGNodeSwapChild(node, child, index);
	}

	EXPORT void FlexUi_NodeRemoveChild(YGNodeRef node, YGNodeRef child)
	{
		YGNodeRemoveChild(node, child);
	}

	EXPORT void FlexUi_NodeRemoveAllChildren(YGNodeRef node)
	{
		YGNodeRemoveAllChildren(node);
	}

	EXPORT void FlexUi_NodeSetChildren(YGNodeRef owner, const YGNodeRef *children, size_t count)
	{
		YGNodeSetChildren(owner, children, count);
	}

	EXPORT YGNodeRef FlexUi_NodeGetChild(YGNodeRef node, size_t index)
	{
		return YGNodeGetChild(node, index);
	}

	EXPORT size_t FlexUi_NodeGetChildCount(YGNodeConstRef node)
	{
		return YGNodeGetChildCount(node);
	}

	EXPORT YGNodeRef FlexUi_NodeGetOwner(YGNodeRef node)
	{
		return YGNodeGetOwner(node);
	}

	EXPORT YGNodeRef FlexUi_NodeGetParent(YGNodeRef node)
	{
		return YGNodeGetParent(node);
	}

	EXPORT const char *FlexUi_NodeSetConfig(YGNodeRef node, YGConfigRef config)
	{
		try
		{
			YGNodeSetConfig(node, config);
			return NULL;
		}
		catch (std::logic_error err)
		{
			return strdup(err.what());
		}
	}

	EXPORT void FlexUi_NodeSetContext(YGNodeRef node, void *context)
	{
		YGNodeSetContext(node, context);
	}

	EXPORT void *FlexUi_NodeGetContext(YGNodeConstRef node)
	{
		return YGNodeGetContext(node);
	}

	EXPORT void FlexUi_NodeSetMeasureFunc(YGNodeRef node, YGMeasureFunc measureFunc)
	{
		YGNodeSetMeasureFunc(node, measureFunc);
	}

	EXPORT bool FlexUi_NodeHasMeasureFunc(YGNodeConstRef node)
	{
		return YGNodeHasMeasureFunc(node);
	}

	EXPORT void FlexUi_NodeSetBaselineFunc(YGNodeRef node, YGBaselineFunc baselineFunc)
	{
		YGNodeSetBaselineFunc(node, baselineFunc);
	}

	EXPORT bool FlexUi_NodeHasBaselineFunc(YGNodeConstRef node)
	{
		return YGNodeHasBaselineFunc(node);
	}

	EXPORT void FlexUi_NodeSetIsReferenceBaseline(YGNodeRef node, bool isReferenceBaseline)
	{
		YGNodeSetIsReferenceBaseline(node, isReferenceBaseline);
	}

	EXPORT bool FlexUi_NodeIsReferenceBaseline(YGNodeConstRef node)
	{
		return YGNodeIsReferenceBaseline(node);
	}

	EXPORT void FlexUi_NodeSetNodeType(YGNodeRef node, YGNodeType nodeType)
	{
		YGNodeSetNodeType(node, nodeType);
	}

	EXPORT YGNodeType FlexUi_NodeGetNodeType(YGNodeConstRef node)
	{
		return YGNodeGetNodeType(node);
	}

	EXPORT void FlexUi_NodeSetAlwaysFormsContainingBlock(YGNodeRef node, bool alwaysFormsContainingBlock)
	{
		YGNodeSetAlwaysFormsContainingBlock(node, alwaysFormsContainingBlock);
	}

	EXPORT bool FlexUi_NodeGetAlwaysFormsContainingBlock(YGNodeConstRef node)
	{
		return YGNodeGetAlwaysFormsContainingBlock(node);
	}

	EXPORT float FlexUi_NodeLayoutGetLeft(YGNodeConstRef node)
	{
		return YGNodeLayoutGetLeft(node);
	}

	EXPORT float FlexUi_NodeLayoutGetTop(YGNodeConstRef node)
	{
		return YGNodeLayoutGetTop(node);
	}

	EXPORT float FlexUi_NodeLayoutGetRight(YGNodeConstRef node)
	{
		return YGNodeLayoutGetRight(node);
	}

	EXPORT float FlexUi_NodeLayoutGetBottom(YGNodeConstRef node)
	{
		return YGNodeLayoutGetBottom(node);
	}

	EXPORT float FlexUi_NodeLayoutGetWidth(YGNodeConstRef node)
	{
		return YGNodeLayoutGetWidth(node);
	}

	EXPORT float FlexUi_NodeLayoutGetHeight(YGNodeConstRef node)
	{
		return YGNodeLayoutGetHeight(node);
	}

	EXPORT YGDirection NodeLayoutGetDirection(YGNodeConstRef node)
	{
		return YGNodeLayoutGetDirection(node);
	}

	EXPORT bool FlexUi_NodeLayoutGetHadOverflow(YGNodeConstRef node)
	{
		return YGNodeLayoutGetHadOverflow(node);
	}

	EXPORT float FlexUi_NodeLayoutGetMargin(YGNodeConstRef node, YGEdge edge)
	{
		return YGNodeLayoutGetMargin(node, edge);
	}

	EXPORT float FlexUi_NodeLayoutGetBorder(YGNodeConstRef node, YGEdge edge)
	{
		return YGNodeLayoutGetBorder(node, edge);
	}

	EXPORT float FlexUi_NodeLayoutGetPadding(YGNodeConstRef node, YGEdge edge)
	{
		return YGNodeLayoutGetPadding(node, edge);
	}

	EXPORT void FlexUI_NodeCopyStyle(YGNodeRef dstNode, YGNodeConstRef srcNode)
	{
		YGNodeCopyStyle(dstNode, srcNode);
	}

	EXPORT void FlexUi_NodeStyleSetDirection(YGNodeRef node, YGDirection direction)
	{
		YGNodeStyleSetDirection(node, direction);
	}

	EXPORT YGDirection FlexUi_NodeStyleGetDirection(YGNodeRef node)
	{
		return YGNodeStyleGetDirection(node);
	}

	EXPORT void FlexUi_NodeStyleSetFlexDirection(YGNodeRef node, YGFlexDirection flexDirection)
	{
		YGNodeStyleSetFlexDirection(node, flexDirection);
	}

	EXPORT YGFlexDirection FlexUi_NodeStyleGetFlexDirection(YGNodeRef node)
	{
		return YGNodeStyleGetFlexDirection(node);
	}

	EXPORT void FlexUi_NodeStyleSetJustifyContent(YGNodeRef node, YGJustify justifyContent)
	{
		YGNodeStyleSetJustifyContent(node, justifyContent);
	}

	EXPORT YGJustify FlexUi_NodeStyleGetJustifyContent(YGNodeRef node)
	{
		return YGNodeStyleGetJustifyContent(node);
	}

	EXPORT void FlexUi_NodeStyleSetAlignContent(YGNodeRef node, YGAlign alignContent)
	{
		YGNodeStyleSetAlignContent(node, alignContent);
	}

	EXPORT YGAlign FlexUi_NodeStyleGetAlignContent(YGNodeRef node)
	{
		return YGNodeStyleGetAlignContent(node);
	}

	EXPORT void FlexUi_NodeStyleSetAlignItems(YGNodeRef node, YGAlign alignItems)
	{
		YGNodeStyleSetAlignItems(node, alignItems);
	}

	EXPORT YGAlign FlexUi_NodeStyleGetAlignItems(YGNodeRef node)
	{
		return YGNodeStyleGetAlignItems(node);
	}

	EXPORT void FlexUi_NodeStyleSetAlignSelf(YGNodeRef node, YGAlign alignSelf)
	{
		YGNodeStyleSetAlignSelf(node, alignSelf);
	}

	EXPORT YGAlign FlexUi_NodeStyleGetAlignSelf(YGNodeRef node)
	{
		return YGNodeStyleGetAlignSelf(node);
	}

	EXPORT void FlexUi_NodeStyleSetPositionType(YGNodeRef node, YGPositionType positionType)
	{
		YGNodeStyleSetPositionType(node, positionType);
	}

	EXPORT YGPositionType FlexUi_NodeStyleGetPositionType(YGNodeRef node)
	{
		return YGNodeStyleGetPositionType(node);
	}

	EXPORT void FlexUi_NodeStyleSetFlexWrap(YGNodeRef node, YGWrap flexWrap)
	{
		YGNodeStyleSetFlexWrap(node, flexWrap);
	}

	EXPORT YGWrap FlexUi_NodeStyleGetFlexWrap(YGNodeRef node)
	{
		return YGNodeStyleGetFlexWrap(node);
	}

	EXPORT void FlexUi_NodeStyleSetOverflow(YGNodeRef node, YGOverflow overflow)
	{
		YGNodeStyleSetOverflow(node, overflow);
	}

	EXPORT YGOverflow FlexUi_NodeStyleGetOverflow(YGNodeRef node)
	{
		return YGNodeStyleGetOverflow(node);
	}

	EXPORT void FlexUi_NodeStyleSetDisplay(YGNodeRef node, YGDisplay display)
	{
		YGNodeStyleSetDisplay(node, display);
	}

	EXPORT YGDisplay FlexUi_NodeStyleGetDisplay(YGNodeRef node)
	{
		return YGNodeStyleGetDisplay(node);
	}

	EXPORT void FlexUi_NodeStyleSetFlex(YGNodeRef node, float flex)
	{
		YGNodeStyleSetFlex(node, flex);
	}

	EXPORT float FlexUi_NodeStyleGetFlex(YGNodeRef node)
	{
		return YGNodeStyleGetFlex(node);
	}

	EXPORT void FlexUi_NodeStyleSetFlexGrow(YGNodeRef node, float flexGrow)
	{
		YGNodeStyleSetFlexGrow(node, flexGrow);
	}

	EXPORT float FlexUi_NodeStyleGetFlexGrow(YGNodeRef node)
	{
		return YGNodeStyleGetFlexGrow(node);
	}

	EXPORT void FlexUi_NodeStyleSetFlexShrink(YGNodeRef node, float flexShrink)
	{
		YGNodeStyleSetFlexShrink(node, flexShrink);
	}

	EXPORT float FlexUi_NodeStyleGetFlexShrink(YGNodeRef node)
	{
		return YGNodeStyleGetFlexShrink(node);
	}

	EXPORT void FlexUi_NodeStyleSetFlexBasis(YGNodeRef node, float flexBasis)
	{
		YGNodeStyleSetFlexBasis(node, flexBasis);
	}

	EXPORT void FlexUi_NodeStyleSetFlexBasisPercent(YGNodeRef node, float flexBasis)
	{
		YGNodeStyleSetFlexBasisPercent(node, flexBasis);
	}

	EXPORT void FlexUi_NodeStyleSetFlexBasisAuto(YGNodeRef node)
	{
		YGNodeStyleSetFlexBasisAuto(node);
	}

	EXPORT YGValue FlexUi_NodeStyleGetFlexBasis(YGNodeRef node)
	{
		return YGNodeStyleGetFlexBasis(node);
	}

	EXPORT void FlexUi_NodeStyleSetPosition(YGNodeRef node, YGEdge edge, float position)
	{
		YGNodeStyleSetPosition(node, edge, position);
	}

	EXPORT void FlexUi_NodeStyleSetPositionPercent(YGNodeRef node, YGEdge edge, float position)
	{
		YGNodeStyleSetPositionPercent(node, edge, position);
	}

	EXPORT YGValue FlexUi_NodeStyleGetPosition(YGNodeConstRef node, YGEdge edge)
	{
		return YGNodeStyleGetPosition(node, edge);
	}

	EXPORT void FlexUi_NodeStyleSetMargin(YGNodeRef node, YGEdge edge, float margin)
	{
		YGNodeStyleSetMargin(node, edge, margin);
	}

	EXPORT void FlexUi_NodeStyleSetMarginPercent(YGNodeRef node, YGEdge edge, float margin)
	{
		YGNodeStyleSetMarginPercent(node, edge, margin);
	}

	EXPORT void FlexUi_NodeStyleSetMarginAuto(YGNodeRef node, YGEdge edge)
	{
		YGNodeStyleSetMarginAuto(node, edge);
	}

	EXPORT YGValue FlexUi_NodeStyleGetMargin(YGNodeConstRef node, YGEdge edge)
	{
		return YGNodeStyleGetMargin(node, edge);
	}

	EXPORT void FlexUi_NodeStyleSetPadding(YGNodeRef node, YGEdge edge, float padding)
	{
		YGNodeStyleSetPadding(node, edge, padding);
	}

	EXPORT void FlexUi_NodeStyleSetPaddingPercent(YGNodeRef node, YGEdge edge, float padding)
	{
		YGNodeStyleSetPaddingPercent(node, edge, padding);
	}

	EXPORT YGValue FlexUi_NodeStyleGetPadding(YGNodeConstRef node, YGEdge edge)
	{
		return YGNodeStyleGetPadding(node, edge);
	}

	EXPORT void FlexUi_NodeStyleSetBorder(YGNodeRef node, YGEdge edge, float border)
	{
		YGNodeStyleSetBorder(node, edge, border);
	}

	EXPORT float FlexUi_NodeStyleGetBorder(YGNodeConstRef node, YGEdge edge)
	{
		return YGNodeStyleGetBorder(node, edge);
	}

	EXPORT void FlexUi_NodeStyleSetGap(YGNodeRef node, YGGutter gutter, float padding)
	{
		YGNodeStyleSetGap(node, gutter, padding);
	}

	EXPORT void FlexUi_NodeStyleSetGapPercent(YGNodeRef node, YGGutter gutter, float padding)
	{
		YGNodeStyleSetGapPercent(node, gutter, padding);
	}

	EXPORT float FlexUi_NodeStyleGetGap(YGNodeConstRef node, YGGutter gutter)
	{
		return YGNodeStyleGetGap(node, gutter);
	}

	EXPORT void FlexUi_NodeStyleSetWidth(YGNodeRef node, float width)
	{
		YGNodeStyleSetWidth(node, width);
	}

	EXPORT void FlexUi_NodeStyleSetWidthPercent(YGNodeRef node, float width)
	{
		YGNodeStyleSetWidthPercent(node, width);
	}

	EXPORT void FlexUi_NodeStyleSetWidthAuto(YGNodeRef node)
	{
		YGNodeStyleSetWidthAuto(node);
	}

	EXPORT YGValue FlexUi_NodeStyleGetWidth(YGNodeConstRef node)
	{
		return YGNodeStyleGetWidth(node);
	}

	EXPORT void FlexUi_NodeStyleSetHeight(YGNodeRef node, float height)
	{
		YGNodeStyleSetHeight(node, height);
	}

	EXPORT void FlexUi_NodeStyleSetHeightPercent(YGNodeRef node, float height)
	{
		YGNodeStyleSetHeightPercent(node, height);
	}

	EXPORT void FlexUi_NodeStyleSetHeightAuto(YGNodeRef node)
	{
		YGNodeStyleSetHeightAuto(node);
	}

	EXPORT YGValue FlexUi_NodeStyleGetHeight(YGNodeConstRef node)
	{
		return YGNodeStyleGetHeight(node);
	}

	EXPORT void FlexUi_NodeStyleSetMinWidth(YGNodeRef node, float minWidth)
	{
		YGNodeStyleSetMinWidth(node, minWidth);
	}

	EXPORT void FlexUi_NodeStyleSetMinWidthPercent(YGNodeRef node, float minWidth)
	{
		YGNodeStyleSetMinWidthPercent(node, minWidth);
	}

	EXPORT EXPORT YGValue FlexUi_NodeStyleGetMinWidth(YGNodeConstRef node)
	{
		return YGNodeStyleGetMinWidth(node);
	}

	EXPORT void FlexUi_NodeStyleSetMinHeight(YGNodeRef node, float minHeight)
	{
		YGNodeStyleSetMinHeight(node, minHeight);
	}

	EXPORT void FlexUi_NodeStyleSetMinHeightPercent(YGNodeRef node, float minHeight)
	{
		YGNodeStyleSetMinHeightPercent(node, minHeight);
	}

	EXPORT YGValue FlexUi_NodeStyleGetMinHeight(YGNodeConstRef node)
	{
		return YGNodeStyleGetMinHeight(node);
	}

	EXPORT void FlexUi_NodeStyleSetMaxWidth(YGNodeRef node, float maxWidth)
	{
		YGNodeStyleSetMaxWidth(node, maxWidth);
	}

	EXPORT void FlexUi_NodeStyleSetMaxWidthPercent(YGNodeRef node, float maxWidth)
	{
		YGNodeStyleSetMaxWidthPercent(node, maxWidth);
	}

	EXPORT YGValue FlexUi_NodeStyleGetMaxWidth(YGNodeConstRef node)
	{
		return YGNodeStyleGetMaxWidth(node);
	}

	EXPORT void FlexUi_NodeStyleSetMaxHeight(YGNodeRef node, float maxHeight)
	{
		YGNodeStyleSetMaxHeight(node, maxHeight);
	}

	EXPORT void FlexUi_NodeStyleSetMaxHeightPercent(YGNodeRef node, float maxHeight)
	{
		YGNodeStyleSetMaxHeightPercent(node, maxHeight);
	}

	EXPORT YGValue FlexUi_NodeStyleGetMaxHeight(YGNodeConstRef node)
	{
		return YGNodeStyleGetMaxHeight(node);
	}

	EXPORT void FlexUi_NodeStyleSetAspectRatio(YGNodeRef node, float aspectRatio)
	{
		YGNodeStyleSetAspectRatio(node, aspectRatio);
	}

	EXPORT float FlexUi_NodeStyleGetAspectRatio(YGNodeConstRef node)
	{
		return YGNodeStyleGetAspectRatio(node);
	}

	EXPORT float FlexUi_RoundValueToPixelGrid(double value, double pointScaleFactor, bool forceCeil, bool forceFloor)
	{
		return YGRoundValueToPixelGrid(value, pointScaleFactor, forceCeil, forceFloor);
	}
}
