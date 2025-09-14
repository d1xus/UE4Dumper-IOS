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
    kaddr GNamesToFNamePool;//NamePoolData, alignas(FNamePool)
    kaddr FNamePoolToCurrentBlock;
    kaddr FNamePoolToCurrentByteCursor;
    kaddr FNamePoolToBlocks;
    //Class: FNameEntry
    kaddr FNameEntryToLenBit;
    kaddr FNameEntryToString;
    //Class: UStruct
    kaddr UStructToChildProperties;
    //Class: FField
    kaddr FFieldToClass;
    kaddr FFieldToNext;
    kaddr FFieldToName;
    //---------4.18+---------//
    //Class: FNameEntry
    kaddr FNameEntryToNameString;
    //-----------------------//
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
    //Class: UStruct
    kaddr UStructToSuperStruct;
    kaddr UStructToChildren;
    //Class: UFunction
    kaddr UFunctionToFunctionFlags;
    kaddr UFunctionToFunc;
    //Class: UProperty
    kaddr UPropertyToElementSize;
    kaddr UPropertyToPropertyFlags;
    kaddr UPropertyToOffsetInternal;
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
        FUObjectItemSize = 0x18;

        //---------SDK-----------
        //Class: FNameEntry
        FNameEntryToNameString = 0x8;
        //Class: FUObjectArray
        FUObjectArrayToTUObjectArray = 0x10;
        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0x8;
        //Class: UObject
        UObjectToInternalIndex = 0x8;
        UObjectToClassPrivate = 0xC;
        UObjectToFNameIndex = 0x10;
        UObjectToOuterPrivate = 0x18;
        //Class: UField
        UFieldToNext = 0x1C;
        //Class: UStruct
        UStructToSuperStruct = 0x20;
        UStructToChildren = 0x24;
        //Class: UFunction
        UFunctionToFunctionFlags = 0x58;
        UFunctionToFunc = 0x74;
        //Class: UProperty
        UPropertyToElementSize = 0x24;
        UPropertyToPropertyFlags = 0x28;
        UPropertyToOffsetInternal = 0x34;
        //Class: UBoolProperty
        UBoolPropertyToFieldSize = 0x50;
        UBoolPropertyToByteOffset = 0x51;
        UBoolPropertyToByteMask = 0x52;
        UBoolPropertyToFieldMask = 0x53;
        //Class: UObjectProperty
        UObjectPropertyToPropertyClass = 0x50;
        //Class: UClassProperty
        UClassPropertyToMetaClass = 0x54;
        //Class: UInterfaceProperty
        UInterfacePropertyToInterfaceClass = 0x54;
        //Class: UArrayProperty
        UArrayPropertyToInnerProperty = 0x50;
        //Class: UMapProperty
        UMapPropertyToKeyProp = 0x50;
        UMapPropertyToValueProp = 0x54;
        //Class: USetProperty
        USetPropertyToElementProp = 0x50;
        //Class: UStructProperty
        UStructPropertyToStruct = 0x50;
        //Class: UWorld
        UWorldToPersistentLevel = 0x20;
        //Class: ULevel
        ULevelToAActors = 0x70;
        ULevelToAActorsCount = 0x74;
    }

    void patchUE423_32() {
        //General
        FUObjectItemSize = 0x18;

        //Class: FNamePool (from provided offsets)
        FNameStride = 0x2;
        GNamesToFNamePool = 0xc8;
        FNamePoolToBlocks = 0xc8;

        //Class: FNameEntry (mapped)
        FNameEntryToLenBit = 0x12;    // 18 decimal -> 0x12
        FNameEntryToString = 0x4;

        //Class: FUObjectArray / TUObjectArray
        FUObjectArrayToTUObjectArray = 0x10; // FUObjectArray::ObjObjects = 0x10
        TUObjectArrayToNumElements = 0x4;    // TUObjectArray::NumElements = 0x4

        //Class: UStruct
        UStructToChildProperties = 0x68; // UStruct::ChildProperties = 0x68
        UStructToSuperStruct = 0x40;     // UStruct::SuperStruct = 0x40
        UStructToChildren = 0x50;        // UStruct::Children = 0x50

        //Class: FField
        FFieldToClass = 0x20; // FField::ClassPrivate = 0x20
        FFieldToNext = 0x18;  // FField::Next = 0x18
        FFieldToName = 0x28;  // FField::NamePrivate = 0x28

        //Class: UObject
        UObjectToInternalIndex = 0x24; // UObject::InternalIndex = 0x24
        UObjectToClassPrivate = 0x8;   // UObject::ClassPrivate = 0x8
        UObjectToFNameIndex = 0x1c;    // UObject::NamePrivate = 0x1c
        UObjectToOuterPrivate = 0x10;  // UObject::OuterPrivate = 0x10

        //Class: UField
        UFieldToNext = 0x28; // UField::Next = 0x28

        //Class: UFunction
        UFunctionToFunctionFlags = 0xb8; // UFunction::EFunctionFlags = 0xb8
        UFunctionToFunc = 0xd8;          // UFunction::Func = 0xd8

        //Class: UProperty (from FProperty)
        UPropertyToElementSize = 0x3c;   // FProperty::ElementSize = 0x3c
        UPropertyToPropertyFlags = 0x40; // FProperty::PropertyFlags = 0x40
        UPropertyToOffsetInternal = 0x4c;// FProperty::Offset_Internal = 0x4c
    }

    void patchCustom_32() {

    }

    void initOffsets_64() {
        //Global
        PointerSize = 0x8;
        FUObjectItemSize = 0x18;

        //---------SDK-----------
        //Class: FNameEntry
        FNameEntryToNameString = 0x10;
        //Class: FUObjectArray
        FUObjectArrayToTUObjectArray = 0x10;
        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0xC;
        //Class: UObject
        UObjectToInternalIndex = 0xC;
        UObjectToClassPrivate = 0x10;
        UObjectToFNameIndex = 0x18;
        UObjectToOuterPrivate = 0x20;
        //Class: UField
        UFieldToNext = 0x28;
        //Class: UStruct
        UStructToSuperStruct = 0x30;
        UStructToChildren = 0x38;
        //Class: UFunction
        UFunctionToFunctionFlags = 0x88;
        UFunctionToFunc = 0xB0;
        //Class: UProperty
        UPropertyToElementSize = 0x34;
        UPropertyToPropertyFlags = 0x38;
        UPropertyToOffsetInternal = 0x44;
        //Class: UBoolProperty
        UBoolPropertyToFieldSize = 0x70;
        UBoolPropertyToByteOffset = 0x71;
        UBoolPropertyToByteMask = 0x72;
        UBoolPropertyToFieldMask = 0x73;
        //Class: UObjectProperty
        UObjectPropertyToPropertyClass = 0x70;
        //Class: UClassProperty
        UClassPropertyToMetaClass = 0x78;
        //Class: UInterfaceProperty
        UInterfacePropertyToInterfaceClass = 0x78;
        //Class: UArrayProperty
        UArrayPropertyToInnerProperty = 0x70;
        //Class: UMapProperty
        UMapPropertyToKeyProp = 0x70;
        UMapPropertyToValueProp = 0x78;
        //Class: USetProperty
        USetPropertyToElementProp = 0x70;
        //Class: UStructProperty
        UStructPropertyToStruct = 0x70;
        //Class: UWorld
        UWorldToPersistentLevel = 0x30;
        //Class: ULevel
        ULevelToAActors = 0x98;
        ULevelToAActorsCount = 0xA0;
    }

    void patchUE423_64() {
        //General
        FUObjectItemSize = 0x18;

        //Class: FNamePool (from provided offsets)
        FNameStride = 0x2;
        GNamesToFNamePool = 0xc8;
        FNamePoolToBlocks = 0xc8;

        //Class: FNameEntry (mapped)
        FNameEntryToLenBit = 0x12;    // 18 decimal -> 0x12
        FNameEntryToString = 0x4;

        //Class: FUObjectArray / TUObjectArray
        FUObjectArrayToTUObjectArray = 0x10; // FUObjectArray::ObjObjects = 0x10
        TUObjectArrayToNumElements = 0x4;    // TUObjectArray::NumElements = 0x4

        //Class: UStruct
        UStructToChildProperties = 0x68; // UStruct::ChildProperties = 0x68
        UStructToSuperStruct = 0x40;     // UStruct::SuperStruct = 0x40
        UStructToChildren = 0x50;        // UStruct::Children = 0x50

        //Class: FField
        FFieldToClass = 0x20; // FField::ClassPrivate = 0x20
        FFieldToNext = 0x18;  // FField::Next = 0x18
        FFieldToName = 0x28;  // FField::NamePrivate = 0x28

        //Class: UObject
        UObjectToInternalIndex = 0x24; // UObject::InternalIndex = 0x24
        UObjectToClassPrivate = 0x8;   // UObject::ClassPrivate = 0x8
        UObjectToFNameIndex = 0x1c;    // UObject::NamePrivate = 0x1c
        UObjectToOuterPrivate = 0x10;  // UObject::OuterPrivate = 0x10

        //Class: UField
        UFieldToNext = 0x28; // UField::Next = 0x28

        //Class: UFunction
        UFunctionToFunctionFlags = 0xb8; // UFunction::EFunctionFlags = 0xb8
        UFunctionToFunc = 0xd8;          // UFunction::Func = 0xd8

        //Class: UProperty (from FProperty)
        UPropertyToElementSize = 0x3c;   // FProperty::ElementSize = 0x3c
        UPropertyToPropertyFlags = 0x40; // FProperty::PropertyFlags = 0x40
        UPropertyToOffsetInternal = 0x4c;// FProperty::Offset_Internal = 0x4c
    }

    void patchCustom_64() {

        if (isARKSurvival()) {
            //Class: UWorld
            UPropertyToOffsetInternal = 0x50;
            UWorldToPersistentLevel = 0x58;
        }
    }
}

#endif
