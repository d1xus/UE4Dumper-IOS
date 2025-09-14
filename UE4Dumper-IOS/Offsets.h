#ifndef OFFSETS_H
#define OFFSETS_H

#include "Mem.h"

namespace Offsets {
    //Global
    kaddr GWorld;
    kaddr GNames;
    kaddr GUObjectArray;
    kaddr PointerSize;
    kaddr FUObjectItemSize;

    //---------SDK-----------//
    //---------4.23+---------//
    //Class: FNamePool
    kaddr FNameStride;
    kaddr GNamesToFNamePool; //NamePoolData, alignas(FNamePool)
    kaddr FNamePoolToCurrentBlock;
    kaddr FNamePoolToCurrentByteCursor;
    kaddr FNamePoolToBlocks;
    //Class: FNameEntry
    kaddr FNameEntryToLenBit;
    kaddr FNameEntryToString;
    kaddr FNameEntryToNameString;
    //Class: UStruct
    kaddr UStructToChildProperties;
    kaddr UStructToSuperStruct;
    kaddr UStructToChildren;
    //Class: FField
    kaddr FFieldToClass;
    kaddr FFieldToNext;
    kaddr FFieldToName;
    //Class: FUObjectArray
    kaddr FUObjectArrayToTUObjectArray;
    //Class: TUObjectArray
    kaddr TUObjectArrayToNumElements;
    //Class: UObject
    kaddr UObjectToInternalIndex;
    kaddr UObjectToClassPrivate;
    kaddr UObjectToFNameIndex;
    kaddr UObjectToOuterPrivate;
    //Class: UField
    kaddr UFieldToNext;
    //Class: UFunction
    kaddr UFunctionToFunctionFlags;
    kaddr UFunctionToNumParams;
    kaddr UFunctionToParamSize;
    kaddr UFunctionToFunc;
    //Class: FField
    kaddr FFieldToFlagsPrivate;
    //Class: FProperty
    kaddr FPropertyToArrayDim;
    kaddr FPropertyToElementSize;
    kaddr FPropertyToPropertyFlags;
    kaddr FPropertyToOffsetInternal;
    kaddr FPropertyToSize;
    //Class: UBoolProperty
    kaddr UBoolPropertyToFieldSize;
    kaddr UBoolPropertyToByteOffset;
    kaddr UBoolPropertyToByteMask;
    kaddr UBoolPropertyToFieldMask;
    //Class: UObjectProperty
    kaddr UObjectPropertyToPropertyClass;
    //Class: UClassProperty
    kaddr UClassPropertyToMetaClass;
    //Class: UInterfaceProperty
    kaddr UInterfacePropertyToInterfaceClass;
    //Class: UArrayProperty
    kaddr UArrayPropertyToInnerProperty;
    //Class: UMapProperty
    kaddr UMapPropertyToKeyProp;
    kaddr UMapPropertyToValueProp;
    //Class: USetProperty
    kaddr USetPropertyToElementProp;
    //Class: UStructProperty
    kaddr UStructPropertyToStruct;
    //Class: UWorld
    kaddr UWorldToPersistentLevel;
    //Class: ULevel
    kaddr ULevelToAActors;
    kaddr ULevelToAActorsCount;

    void initOffsets_32() {
        //Global
        PointerSize = 0x4;
        FUObjectItemSize = 0x18; // из твоего списка

        //---------SDK-----------
        //Class: FNameEntry
        FNameEntryToNameString = 0x8; 
        //Class: FUObjectArray
        FUObjectArrayToTUObjectArray = 0x10;
        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0x4; 
        //Class: UObject
        UObjectToInternalIndex = 0x24;
        UObjectToClassPrivate = 0x8;
        UObjectToFNameIndex = 0x0; // старое
        UObjectToOuterPrivate = 0x10;
        //Class: UField
        UFieldToNext = 0x28;
        //Class: UStruct
        UStructToSuperStruct = 0x40;
        UStructToChildren = 0x50;
        UStructToChildProperties = 0x68;
        //Class: UFunction
        UFunctionToFunctionFlags = 0xb8;
        UFunctionToNumParams = 0xb0;
        UFunctionToParamSize = 0xb2;
        UFunctionToFunc = 0xd8;
        //Class: FField
        FFieldToClass = 0x20;
        FFieldToNext = 0x18;
        FFieldToName = 0x28;
        FFieldToFlagsPrivate = 0x8;
        //Class: FProperty
        FPropertyToArrayDim = 0x38;
        FPropertyToElementSize = 0x3c;
        FPropertyToPropertyFlags = 0x40;
        FPropertyToOffsetInternal = 0x4c;
        FPropertyToSize = 0x78;

        //Остальные оставляем как есть
        UBoolPropertyToFieldSize = 0x50;
        UBoolPropertyToByteOffset = 0x51;
        UBoolPropertyToByteMask = 0x52;
        UBoolPropertyToFieldMask = 0x53;
        UObjectPropertyToPropertyClass = 0x50;
        UClassPropertyToMetaClass = 0x54;
        UInterfacePropertyToInterfaceClass = 0x54;
        UArrayPropertyToInnerProperty = 0x50;
        UMapPropertyToKeyProp = 0x50;
        UMapPropertyToValueProp = 0x54;
        USetPropertyToElementProp = 0x50;
        UStructPropertyToStruct = 0x50;
        UWorldToPersistentLevel = 0x20;
        ULevelToAActors = 0x70;
        ULevelToAActorsCount = 0x74;
    }

    void patchUE423_32() {
        //Class: FNamePool
        FNameStride = 2;
        GNamesToFNamePool = 0xc8;
        FNamePoolToCurrentBlock = 0x0; // оставлено старое
        FNamePoolToCurrentByteCursor = 0x0; // оставлено старое
        FNamePoolToBlocks = 0x0; // оставлено старое
        //Class: FNameEntry
        FNameEntryToLenBit = 18;
        FNameEntryToString = 0x4; 
        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0x10000; 
        //Class: UStruct
        UStructToChildProperties = 0x68;
        //Class: FField
        FFieldToClass = 0x20;
        FFieldToNext = 0x18;
        FFieldToName = 0x28;
    }

    void initOffsets_64() {
        //Global
        PointerSize = 0x8;
        FUObjectItemSize = 0x18;

        //Class: FNameEntry
        FNameEntryToNameString = 0x10;
        //Class: FUObjectArray
        FUObjectArrayToTUObjectArray = 0x10;
        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0x4; 
        //Class: UObject
        UObjectToInternalIndex = 0x24;
        UObjectToClassPrivate = 0x8;
        UObjectToFNameIndex = 0x0;
        UObjectToOuterPrivate = 0x10;
        //Class: UField
        UFieldToNext = 0x28;
        //Class: UStruct
        UStructToSuperStruct = 0x40;
        UStructToChildren = 0x50;
        UStructToChildProperties = 0x68;
        //Class: UFunction
        UFunctionToFunctionFlags = 0xb8;
        UFunctionToNumParams = 0xb0;
        UFunctionToParamSize = 0xb2;
        UFunctionToFunc = 0xd8;
        //Class: FField
        FFieldToClass = 0x20;
        FFieldToNext = 0x18;
        FFieldToName = 0x28;
        FFieldToFlagsPrivate = 0x8;
        //Class: FProperty
        FPropertyToArrayDim = 0x38;
        FPropertyToElementSize = 0x3c;
        FPropertyToPropertyFlags = 0x40;
        FPropertyToOffsetInternal = 0x4c;
        FPropertyToSize = 0x78;

        //Остальные оставляем как есть
        UBoolPropertyToFieldSize = 0x70;
        UBoolPropertyToByteOffset = 0x71;
        UBoolPropertyToByteMask = 0x72;
        UBoolPropertyToFieldMask = 0x73;
        UObjectPropertyToPropertyClass = 0x70;
        UClassPropertyToMetaClass = 0x78;
        UInterfacePropertyToInterfaceClass = 0x78;
        UArrayPropertyToInnerProperty = 0x70;
        UMapPropertyToKeyProp = 0x70;
        UMapPropertyToValueProp = 0x78;
        USetPropertyToElementProp = 0x70;
        UStructPropertyToStruct = 0x70;
        UWorldToPersistentLevel = 0x30;
        ULevelToAActors = 0x98;
        ULevelToAActorsCount = 0xA0;
    }

    void patchUE423_64() {
        //Class: FNamePool
        FNameStride = 2;
        GNamesToFNamePool = 0xc8;
        FNamePoolToCurrentBlock = 0x0;
        FNamePoolToCurrentByteCursor = 0x0;
        FNamePoolToBlocks = 0x0;
        //Class: FNameEntry
        FNameEntryToLenBit = 18;
        FNameEntryToString = 0x4;
        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0x10000;
        //Class: UStruct
        UStructToChildProperties = 0x68;
        //Class: FField
        FFieldToClass = 0x20;
        FFieldToNext = 0x18;
        FFieldToName = 0x28;
    }

    void patchCustom_32() {}
    void patchCustom_64() {}

}

#endif
