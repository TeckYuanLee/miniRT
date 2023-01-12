Vec3f castRay( 
    const Vec3f &orig, const Vec3f &dir, 
    const std::vector<std::unique_ptr<Object>> &objects, 
    const std::unique_ptr<DistantLight> &light, 
    const Options &options) 
{ 
    Vec3f hitColor = options.backgroundColor; 
    float tnear = kInfinity; 
    Vec2f uv; 
    uint32_t index = 0; 
    Object *hitObject = nullptr; 
    if (trace(orig, dir, objects, tnear, index, uv, &hitObject)) { 
        Vec3f hitPoint = orig + dir * tnear; 
        Vec3f hitNormal; 
        Vec2f hitTexCoordinates; 
        hitObject->getSurfaceProperties(hitPoint, dir, index, uv, hitNormal, hitTexCoordinates); 
        Vec3f L = -light->dir; 
        // compute the color of diffuse surface illuminated
        // by a single distant light source.
        hitColor = hitObject->albedo / M_PI * light->intensity * light->color * std::max(0.f, hitNormal.dotProduct(L)); 
    } 
    return hitColor; 
}