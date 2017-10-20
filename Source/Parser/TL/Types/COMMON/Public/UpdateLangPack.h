#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/LangPackDifference.h"

//begin namespace block
namespace COMMON
{
class UpdateLangPack : public TLBaseObject
{
public:
	UpdateLangPack();
	UpdateLangPack(COMMON::LangPackDifference* difference);

	~UpdateLangPack();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::LangPackDifference*  Getdifference() const
	{
		 return this->difference;
	}

private:
	COMMON::LangPackDifference* difference;
};
} //end namespace block
