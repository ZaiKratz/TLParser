#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputGeoPoint.h"

//begin namespace block
namespace COMMON
{
class InputGeoPointEmpty : public TLBaseObject
{
public:
	InputGeoPointEmpty();
	~InputGeoPointEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
