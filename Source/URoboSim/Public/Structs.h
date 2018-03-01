#pragma once


#include "IURoboSim.h"
#include "Structs.generated.h"

USTRUCT()
struct UROBOSIM_API FRConnectedJoint
{
  GENERATED_USTRUCT_BODY()
    UPROPERTY(EditAnywhere)
  FString Name;
  UPROPERTY(EditAnywhere)
  FString Type;

  UPROPERTY(EditAnywhere)
  bool bIsParent;

  FVector Location;
  FRotator Rotation;

  bool operator== (const FRConnectedJoint &Joint)
  {
	return Name.Equals(Joint.Name);
  }

  bool operator== (const FString &String)
  {
	return Name.Equals(String);
  }
};

USTRUCT()
struct UROBOSIM_API FRControllerDesciption
{
  GENERATED_USTRUCT_BODY()
    UPROPERTY(EditAnywhere)
    FString TargetName;
  UPROPERTY(EditAnywhere)
    FString ControllerType;

  void Set(FString Name, FString Type)
  {
    TargetName = Name;
    ControllerType = Type;
  }

};

struct UROBOSIM_API FRJoint
{

  FString Name;
  FString Type;

  FVector Location;
  FRotator Rotation;

  FString Parent;
  FString Child;

  FVector Axis;

  float LowerLimit;
  float UpperLimit;
  float Effort;
  float Velocity;

  //safety_controller
  float k_velocity;
  //dynamics
  float damping;
  float friction;

  bool operator== (const FRJoint &Joint)
  {
	return Name.Equals(Joint.Name);
  }

  bool operator== (const FString &String)
  {
	return Name.Equals(String);
  }
};

// A structure representing a URDF Link

struct UROBOSIM_API FRLink
{

  FString Name;

  struct
  {
	FVector Location;
	FRotator Rotation;
	float Mass;
  } Inertial;

  struct
  {
	FVector Location;
	FRotator Rotation;
	FString Mesh;
	FVector Scale;

	// Optional. The material of the visual element.
	struct
	{
	  FString Name;
	  FColor Color;
	  FString Texture;
	} Material;
  } Visual;

  struct
  {
	FVector Location;
	FRotator Rotation;
	FString Mesh;
	FVector Scale;
  } Collision;

  bool operator== (const FRLink &Link)
  {
	return Name.Equals(Link.Name);
  }
  bool operator== (const FString &String)
  {
	return Name.Equals(String);
  }
};

// Node to represent the Robot virtually as a tree
struct UROBOSIM_API FRNode
{
  FRLink Link;
  FRJoint Joint;

  FRNode* Parent;
  TArray<FRNode*> Children;

  ~FRNode()
    {
      for (int c = 0; c < Children.Num(); c++)
        {
          delete Children[c];
        }
    }
};
