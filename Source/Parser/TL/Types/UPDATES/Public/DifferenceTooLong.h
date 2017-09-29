#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Updates/Public/Difference.h"

//begin namespace block
namespace UPDATES
{
class DifferenceTooLong : public TLBaseObject
{
public:
	DifferenceTooLong();
	DifferenceTooLong(int32 pts);

	~DifferenceTooLong();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getpts() const
	{
		 return this->pts;
	}

private:
	int32 pts;
};
} //end namespace block
