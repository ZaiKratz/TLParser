#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Updates/Public/Difference.h"

//begin namespace block
namespace UPDATES
{
class DifferenceEmpty : public TLBaseObject
{
public:
	DifferenceEmpty();
	DifferenceEmpty(FDateTime date, int32 seq);

	~DifferenceEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FDateTime date;
	 int32 seq;
};
} //end namespace block
