/*
 * Material.h
 *
 *  Created on: Nov 9, 2013
 *      Author: jonas
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

class Material {

private:
	ColorRGB color;

	float specularity;
	float opacity;
	float refractiveIndex;
	float absorption;

public:
	//will produce a nice solid pink material
	Material() {
		color = ColorRGB(1.0, 0.4, 0.8);
		specularity = 0.0;
		opacity = 1.0;
		refractiveIndex = 1.0;
		absorption = 0;
	}

	float getAbsorbtion() const {
		return absorption;
	}

	void setAbsorbtion(float absorption) {
		this->absorption = absorption;
	}

	const ColorRGB& getColor() const {
		return color;
	}

	void setColor(const ColorRGB& color) {
		this->color = color;
	}

	float getOpacity() const {
		return opacity;
	}

	void setOpacity(float opacity) {
		this->opacity = opacity;
	}

	float getRefractionIndex() const {
		return refractiveIndex;
	}

	void setRefractionIndex(float refractiveIndex) {
		this->refractiveIndex = refractiveIndex;
	}

	float getSpecularity() const {
		return specularity;
	}

	void setSpecularity(float specularity) {
		this->specularity = specularity;
	}
};

#endif /* MATERIAL_H_ */
