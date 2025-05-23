FROM node:18-alpine AS builder

WORKDIR /app
COPY package.json ./
RUN npm install
COPY . . 
RUN npm run build || cat /app/package.json

FROM nginx:alpine

COPY --from=builder /app /usr/share/nginx/html

EXPOSE 8080
HEALTHCHECK --interval=10s --timeout=1s CMD curl -f http://localhost:8080/ || exit 1
CMD ["nginx", "-g", "daemon off"]