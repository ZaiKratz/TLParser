#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/LangPackDifference.h"

//begin namespace block
namespace LANGPACK
{
class GetDifference : public TLBaseObject
{
public:
	GetDifference();
	GetDifference(int32 from_version);

	~GetDifference();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 from_version;
	COMMON::LangPackDifference* result;
};
} //end namespace block
