// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "RURDFData.generated.h"

/**
 * This object is created as uAsset and secures the information for the construction of RRobots.
 */
UCLASS()
class UNREALROBOTSP3_API URURDFData : public UObject
{
	GENERATED_BODY()

public:

#if WITH_EDITOR

	/** Saves the XML */
	UPROPERTY(VisibleAnywhere, AssetRegistrySearchable)
		FString Xml;

	/** For Drag and Drop reimport. */

	/** Saves the asst filename */
	FString Assetfilename;

	/** For reimport. Set the new Assetfilename.
	* @param NewFilename String with the name.
	*/
	void SetAssetFilename(const FString &NewFilename);

	/** For reimport. Set the XML of the RURDFData
	* @param NewXml String with the reimported Xml
	*/
	void SetXml(const FString NewXml);

	/** For reimport. Get the AssetFilename.
	* @return FString Assetfilename of the RURDFData.
	*/
	FString GetAssetFilename() const;

	/** For reimport. Includes the reimport information. */
	UPROPERTY(VisibleAnywhere, Instanced, Category = ImportSettings)
	class UAssetImportData* AssetImportData;

	/** For reimport. Creates AssetImportData for reimport */
	void PostInitProperties() override;

#endif
};