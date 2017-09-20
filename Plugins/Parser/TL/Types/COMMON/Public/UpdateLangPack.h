#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Common/Public/LangPackDifference.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateLangPack : public PRIVATE::Update
{
public:
	UpdateLangPack();
	UpdateLangPack(COMMON::LangPackDifference* difference);

	~UpdateLangPack();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::LangPackDifference* difference;
};
} //end namespace block
